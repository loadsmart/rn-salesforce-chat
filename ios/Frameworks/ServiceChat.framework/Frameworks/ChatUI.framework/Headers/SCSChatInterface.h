//
//  SCSChatInterface.h
//  ChatUI
//
//  Created by Jeremy Wright on 5/4/18.
//  Copyright © 2018 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@class UNNotification;
@class SCSPrechatObject;
@class SCSChatConfiguration;

/**
 Indicates whether the pre-chat process has completed.
 */
typedef void (^SCSPrechatCompletion)(NSArray<SCSPrechatObject *> * _Nullable prechatFields, BOOL submitted);

NS_ASSUME_NONNULL_BEGIN
/**
 The `SCSChatInterface` class is the main UI interface to the chat SDK.
 This object provides functionality to show a pre-chat form, display the chat
 session UI, and handle notifications.
 
 To get an instance of this class, use the `SCServiceCloud.chatUI` property
 on `+[SCServiceCloud sharedInstance]`.
 
 For core chat behavior unrelated to the UI (such as subscribing to session events), see `SCSChat`.

 @see `SCSChat`
 */
@interface SCSChatInterface : NSObject

/**
 Pass a `UNNotification` to this method to request that the chat feed maximize if required.
 The chat feed will only maximize if the notification was scheduled by this chat client.

 @param notification The `UNNotification` that chat will respond to.
 */
- (void)handleNotification:(UNNotification *)notification;

/**
 Determines whether a notification should be displayed in the foreground.
 Returns `true` if the chat feed is not currently maximized.
 */
- (BOOL)shouldDisplayNotificationInForeground;

/**
 Starts a chat session with the default UI.
 If you want to build your own custom UI, use `-[SCSChat startSessionWithConfiguration:completion:]`
 instead.

 @param configuration  The `SCSChatConfiguration` object which represents the session
 configuration.
 */
- (void)showChatWithConfiguration:(SCSChatConfiguration *)configuration;

/**
 Starts a chat session with the default UI. If you set `showPrechat` to `true`, this method displays
 the pre-chat form with the configured fields before starting a chat session.

 If you wish to configure pre-chat separately, or wish to modify data before starting a chat session
 see `-showPrechatWithFields:completion:`.

 @param configuration `SCSChatConfiguration` object that represents the session configuration.
 @param prechat Indicates whether to display pre-chat UI before starting a session.
                Note: If the `SCSChatConfiguration.prechatFields` property is `nil`, this value is ignored.
 */
- (void)showChatWithConfiguration:(SCSChatConfiguration *)configuration showPrechat:(BOOL)prechat;

/**
 Dismisses the chat interface.
 */
- (void)dismissChat;

/**
 Shows the pre-chat UI with the specified pre-chat fields.
 
 @note If the user cancels, the `prechatFields` contents will be unchanged in the completion block.

 @param prechatFields Array of `SCSPrechatObject` objects that represents the pre-chat configuration.
 @param modal Indicates whether this view displays as a modal UI (`true`), or as a non-modal full-screen UI (`false`).
 @param completion Contains an array of pre-chat fields populated with the user input.
                   Also includes a `BOOL` determining whether the user submitted the form without canceling.
 */
- (void)showPrechatWithFields:(NSArray<SCSPrechatObject *> *)prechatFields modal:(BOOL)modal completion:(SCSPrechatCompletion)completion;

/**
 Shows the pre-chat UI with the specified pre-chat fields. This method shows a non-modal, full-screen view.
 To support a modal view, see `-showPrechatWithFields:modal:completion:`.

 @note If the user cancels, the `prechatFields` contents will be unchanged in the completion block.

 @param prechatFields Array of `SCSPrechatObject` objects that represents the pre-chat configuration.
 @param completion Contains an array of pre-chat fields populated with the user input.
 Also includes a `BOOL` that indicates whether the user submitted the form without canceling.
 */
- (void)showPrechatWithFields:(NSArray<SCSPrechatObject *> *)prechatFields completion:(SCSPrechatCompletion)completion;

@end

NS_ASSUME_NONNULL_END
