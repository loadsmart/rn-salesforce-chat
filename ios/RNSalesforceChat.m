#import "RNSalesforceChat.h"

@implementation RNSalesforceChat

NSMutableDictionary<NSString *, SCSPrechatObject *>* prechatFields;
NSMutableDictionary<NSString *, SCSPrechatEntityField *>* prechatEntities;
NSMutableArray* entities;

SCSChatConfiguration *chatConfiguration;

NSString* ChatSessionStateChanged = @"ChatSessionStateChanged";
NSString* ChatSessionEnd = @"ChatSessionEnd";

NSString* Connecting = @"Connecting";
NSString* Queued = @"Queued";
NSString* Connected = @"Connected";
NSString* Ending = @"Ending";
NSString* Disconnected = @"Disconnected";

NSString* EndReasonUser = @"EndReasonUser";
NSString* EndReasonAgent = @"EndReasonAgent";
NSString* EndReasonNoAgentsAvailable = @"EndReasonNoAgentsAvailable";
NSString* EndReasonTimeout = @"EndReasonTimeout";
NSString* EndReasonSessionError = @"EndReasonSessionError";

RCT_EXPORT_MODULE()

+(void) initialize
{
    prechatFields = [[NSMutableDictionary alloc] init];
    prechatEntities = [[NSMutableDictionary alloc] init];
    entities = [[NSMutableArray alloc] init];
}

#pragma mark - RCTBridgeModule

+ (BOOL)requiresMainQueueSetup
{
    return YES;
}

- (NSDictionary *)constantsToExport
{
  return @{
      ChatSessionStateChanged:ChatSessionStateChanged,
      ChatSessionEnd: ChatSessionEnd,
      Connecting: Connecting,
      Queued: Queued,
      Connected: Connected,
      Ending: Ending,
      Disconnected: Disconnected,
      EndReasonUser: EndReasonUser,
      EndReasonAgent: EndReasonAgent,
      EndReasonNoAgentsAvailable: EndReasonNoAgentsAvailable,
      EndReasonTimeout: EndReasonTimeout,
      EndReasonSessionError: EndReasonSessionError
  };
}

RCT_EXPORT_METHOD(createPreChatData:(NSString *)agentLabel value:(NSString *)value
                  isDisplayedToAgent:(BOOL)isDisplayedToAgent transcriptFields:(NSArray<NSString *> *)transcriptFields)
{
    SCSPrechatObject* prechatObject = [[SCSPrechatObject alloc] initWithLabel:agentLabel value:value];
    prechatObject.displayToAgent = isDisplayedToAgent;

    if (transcriptFields != nil) {
        NSMutableArray* receivedTranscriptFields = [transcriptFields mutableCopy];
        prechatObject.transcriptFields = receivedTranscriptFields;
    }
    
    prechatFields[agentLabel] = prechatObject;
}

RCT_EXPORT_METHOD(createEntityField:(NSString *)objectFieldName doCreate:(BOOL)doCreate doFind:(BOOL)doFind
                  isExactMatch:(BOOL)isExactMatch keyChatUserDataToMap:(NSString *)keyChatUserDataToMap)
{
    if (prechatFields[keyChatUserDataToMap] != nil) {
        SCSPrechatEntityField* entityField = [[SCSPrechatEntityField alloc] initWithFieldName:objectFieldName
                                                                                        label:keyChatUserDataToMap];
        entityField.doFind = doFind;
        entityField.doCreate = doCreate;
        entityField.isExactMatch = isExactMatch;

        prechatEntities[objectFieldName] = entityField;
    }
}

RCT_EXPORT_METHOD(createEntity:(NSString *)objectType linkToTranscriptField:(NSString *)linkToTranscriptField
                  showOnCreate:(BOOL)showOnCreate keysEntityFieldToLink:(NSArray<NSString *> *)keysEntityFieldToMap)
{
    SCSPrechatEntity* entity = [[SCSPrechatEntity alloc] initWithEntityName:objectType];
    entity.showOnCreate = showOnCreate;

    if (linkToTranscriptField != nil) {
        entity.saveToTranscript = linkToTranscriptField;
    }

    for (id entityFieldKey in keysEntityFieldToMap) {
        if (prechatEntities[entityFieldKey] != nil) {
            [entity.entityFieldsMaps addObject:prechatEntities[entityFieldKey]];
        }
    }

    [entities addObject:entity];
}

RCT_EXPORT_METHOD(configureChat:(NSString *)orgId buttonId:(NSString *)buttonId deploymentId:(NSString *)deploymentId
                  liveAgentPod:(NSString *)liveAgentPod visitorName:(NSString *)visitorName)
{
    chatConfiguration = [[SCSChatConfiguration alloc] initWithLiveAgentPod:liveAgentPod orgId:orgId
                                                              deploymentId:deploymentId buttonId:buttonId];

    if (visitorName != nil) chatConfiguration.visitorName = visitorName;
    chatConfiguration.prechatFields = [prechatFields allValues];
    chatConfiguration.prechatEntities = entities;
}

RCT_EXPORT_METHOD(openChat:(RCTResponseSenderBlock)failureCallback successCallback:(RCTResponseSenderBlock)successCallback)
{
    if (chatConfiguration == nil) {
        failureCallback(@[@"error - chat not configured"]);
        return;
    }

    [[SCServiceCloud sharedInstance].chatCore removeDelegate:self];
    [[SCServiceCloud sharedInstance].chatCore addDelegate:self];
    [[SCServiceCloud sharedInstance].chatUI showChatWithConfiguration:chatConfiguration];
    successCallback(@[[NSNull null]]);
}

- (NSArray<NSString *> *)supportedEvents
{
  return @[ChatSessionEnd, ChatSessionStateChanged];
}

#pragma mark - SCSChatSessionDelegate

- (void)session:(id<SCSChatSession>)session didTransitionFromState:(SCSChatSessionState)previous toState:(SCSChatSessionState)current {

    NSString *state;

    switch (current) {
        case SCSChatSessionStateConnecting:
            state = Connecting;
            break;
        case SCSChatSessionStateQueued:
            state = Queued;
            break;
        case SCSChatSessionStateConnected:
            state = Connected;
            break;
        case SCSChatSessionStateEnding:
            state = Ending;
            break;
        default:
            state = Disconnected;
            break;
    }
    [self sendEventWithName:ChatSessionStateChanged body:@{@"state": state}];
}

- (void)session:(id<SCSChatSession>)session didEnd:(SCSChatSessionEndEvent *)endEvent {

    NSString *endReason;

    switch (endEvent.reason) {
        case SCSChatEndReasonUser:
            endReason = EndReasonUser;
            break;
        case SCSChatEndReasonAgent:
            endReason = EndReasonAgent;
            break;
        case SCSChatEndReasonNoAgentsAvailable:
            endReason = EndReasonNoAgentsAvailable;
            break;
        case SCSChatEndReasonTimeout:
            endReason = EndReasonTimeout;
            break;
        default:
            endReason = EndReasonSessionError;
    }

    [self sendEventWithName:ChatSessionEnd body:@{@"reason": endReason}];
}


- (void)session:(id<SCSChatSession>)session didError:(NSError *)error fatal:(BOOL)fatal {
    // not used
}

@end
