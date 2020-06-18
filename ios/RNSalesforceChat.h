#import <Foundation/Foundation.h>
#import <React/RCTBridgeModule.h>
#import <React/RCTEventEmitter.h>

@import ServiceCore;
@import ServiceChat;

@interface RNSalesforceChat : RCTEventEmitter <RCTBridgeModule, SCSChatSessionDelegate>
@end
