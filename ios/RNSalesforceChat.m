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

NSString* BrandPrimary = @"BrandPrimary";
NSString* BrandSecondary = @"BrandSecondary";
NSString* BrandSecondaryInverted = @"BrandSecondaryInverted";
NSString* ContrastPrimary = @"ContrastPrimary";
NSString* ContrastQuaternary = @"ContrastQuaternary";
NSString* ContrastInverted = @"ContrastInverted";
NSString* NavbarBackground = @"NavbarBackground";
NSString* NavbarInverted = @"NavbarInverted";

NSArray *colorTokens;

RCT_EXPORT_MODULE()

+(void) initialize
{
    prechatFields = [[NSMutableDictionary alloc] init];
    prechatEntities = [[NSMutableDictionary alloc] init];
    entities = [[NSMutableArray alloc] init];
    colorTokens = @[BrandPrimary,
                    BrandSecondary,
                    BrandSecondaryInverted,
                    ContrastPrimary,
                    ContrastQuaternary,
                    ContrastInverted,
                    NavbarBackground,
                    NavbarInverted
   ];
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
      EndReasonSessionError: EndReasonSessionError,
      BrandPrimary: BrandPrimary,
      BrandSecondary: BrandSecondary,
      BrandSecondaryInverted: BrandSecondaryInverted,
      ContrastPrimary: ContrastPrimary,
      ContrastQuaternary: ContrastQuaternary,
      ContrastInverted: ContrastInverted,
      NavbarBackground: NavbarBackground,
      NavbarInverted: NavbarInverted,
  };
}

RCT_EXPORT_METHOD(createPreChatData:(NSString *)agentLabel value:(NSString *)value
                  isDisplayedToAgent:(BOOL)isDisplayedToAgent transcriptFields:(NSArray<NSString *> *)transcriptFields
                  preChatDataKey:(NSString *)preChatDataKey)
{
    SCSPrechatObject* prechatObject = [[SCSPrechatObject alloc] initWithLabel:agentLabel value:value];
    prechatObject.displayToAgent = isDisplayedToAgent;

    if (transcriptFields != nil) {
        NSMutableArray* receivedTranscriptFields = [transcriptFields mutableCopy];
        prechatObject.transcriptFields = receivedTranscriptFields;
    }

    prechatFields[preChatDataKey] = prechatObject;
}

RCT_EXPORT_METHOD(createEntityField:(NSString *)objectFieldName doCreate:(BOOL)doCreate doFind:(BOOL)doFind
                  isExactMatch:(BOOL)isExactMatch preChatDataKeyToMap:(NSString *)preChatDataKeyToMap
                  entityFieldKey:(NSString *)entityFieldKey)
{
    if (prechatFields[preChatDataKeyToMap] != nil) {

        SCSPrechatEntityField* entityField = [[SCSPrechatEntityField alloc] initWithFieldName:objectFieldName
                                                                                        label:prechatFields[preChatDataKeyToMap].label];
        entityField.doFind = doFind;
        entityField.doCreate = doCreate;
        entityField.isExactMatch = isExactMatch;

        prechatEntities[entityFieldKey] = entityField;
    }
}

RCT_EXPORT_METHOD(createEntity:(NSString *)objectType linkToTranscriptField:(NSString *)linkToTranscriptField
                  showOnCreate:(BOOL)showOnCreate entityFieldKeysToMap:(NSArray<NSString *> *)entityFieldKeysToMap)
{
    SCSPrechatEntity* entity = [[SCSPrechatEntity alloc] initWithEntityName:objectType];
    entity.showOnCreate = showOnCreate;

    if (linkToTranscriptField != nil) {
        entity.saveToTranscript = linkToTranscriptField;
    }

    for (id entityFieldKey in entityFieldKeysToMap) {
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

RCT_EXPORT_METHOD(setupChatColorIOS:(double)redValue greenValue:(double)greenValue blueValue:(double)blueValue alphaValue:(double)alphaValue colorToken:(NSString *)colorToken)
{
    SCAppearanceConfiguration *appearance = [SCServiceCloud sharedInstance].appearanceConfiguration;
    UIColor *color = [UIColor colorWithRed:(float)redValue/255.0f green:(float)greenValue/255.0f blue:(float)blueValue/255.0f alpha:(float) alphaValue];
    
    int colorIndex = (int)[colorTokens indexOfObject:colorToken];
        
    switch (colorIndex) {
        case 0:
            [appearance setColor:color forName:SCSAppearanceColorTokenBrandPrimary];
           break;
        case 1:
            [appearance setColor:color forName:SCSAppearanceColorTokenBrandSecondary];
           break;
        case 2:
            [appearance setColor:color forName:SCSAppearanceColorTokenBrandSecondaryInverted];
           break;
        case 3:
            [appearance setColor:color forName:SCSAppearanceColorTokenContrastPrimary];
           break;
        case 4:
            [appearance setColor:color forName:SCSAppearanceColorTokenContrastQuaternary];
           break;
        case 5:
            [appearance setColor:color forName:SCSAppearanceColorTokenContrastInverted];
           break;
        case 6:
            [appearance setColor:color forName:SCSAppearanceColorTokenNavbarBackground];
           break;
        default:
            [appearance setColor:color forName:SCSAppearanceColorTokenNavbarInverted];
           break;
    }
    
    [SCServiceCloud sharedInstance].appearanceConfiguration = appearance;
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
