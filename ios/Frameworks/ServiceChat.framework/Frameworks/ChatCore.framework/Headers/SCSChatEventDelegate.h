/*
 * Copyright 2016-2018 salesforce.com, inc.
 * All rights reserved.
 *
 * Use of this software is subject to the salesforce.com Developerforce Terms of
 * Use and other applicable terms that salesforce.com may make available, as may be
 * amended from time to time. You may not decompile, reverse engineer, disassemble,
 * attempt to derive the source code of, decrypt, modify, or create derivative
 * works of this software, updates thereto, or any part thereof. You may not use
 * the software to engage in any development activity that infringes the rights of
 * a third party, including that which interferes with, damages, or accesses in an
 * unauthorized manner the servers, networks, or other properties or services of
 * salesforce.com or any third party.
 *
 * WITHOUT LIMITING THE GENERALITY OF THE FOREGOING, THE SOFTWARE IS PROVIDED
 * "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED. IN NO EVENT SHALL
 * SALESFORCE.COM HAVE ANY LIABILITY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO,
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, PUNITIVE, OR CONSEQUENTIAL DAMAGES, OR
 * DAMAGES BASED ON LOST PROFITS, DATA OR USE, IN CONNECTION WITH THE SOFTWARE,
 * HOWEVER CAUSED AND, WHETHER IN CONTRACT, TORT OR UNDER ANY OTHER THEORY OF
 * LIABILITY, WHETHER OR NOT YOU HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGES.
 */

#import <Foundation/Foundation.h>

@class SCSAgentJoinEvent;
@class SCSAgentTextEvent;
@class SCSUserTextEvent;
@class SCSChatBotMenuEvent;
@class SCSChatMenuSelectionEvent;
@class SCSFileTransferEvent;
@class SCSURLEvent;
@class SCSAgentLeftConferenceEvent;

@protocol SCSChatSession;


/**
 The `SCSChatEventDelegate` protocol provides general event information about the chat
 session. Add your implementation to `-[SCSChat addEventDelegate:]`.

 @see `SCSChat`
 @see `SCSChatSessionDelegate`
 */
@protocol SCSChatEventDelegate <NSObject>
@required

/**
 Tells the delegate when an agent joins the chat.

 @param agentjoinedEvent Info about the agent joining the session.

 @see `SCSAgentJoinEvent`
 @see `SCSChatSession`
 */
- (void)session:(id<SCSChatSession>)session agentJoined:(SCSAgentJoinEvent *)agentjoinedEvent;

/**
 Tells the delegate when an agent has left the group conference.
 
 @param session Info about the chat session.
 @param agentLeftConferenceEvent Info about the agent leaving the session.
 
 @see `SCSAgentLeftConferenceEvent`
 @see `SCSChatSession`
 */
- (void)session:(id<SCSChatSession>)session agentLeftConference:(SCSAgentLeftConferenceEvent *)agentLeftConferenceEvent;

/**
 Tells the delegate when an outgoing message has been processed. This does not guarantee
 that the message was sent successfully.
 Inspect the `message` parameter to determine whether the sent message was modified.

 @param message Info about the outgoing message.

 @see `SCSUserTextEvent`
 @see `SCSChatSession`
 */
- (void)session:(id<SCSChatSession>)session processedOutgoingMessage:(SCSUserTextEvent *)message;

/**
 Tells the delegate that the delivery status of a message has been updated.

 @param message Info about the outgoing message.

 @see `SCSUserTextEvent`
 @see `SCSChatSession`
 */
- (void)session:(id<SCSChatSession>)session didUpdateOutgoingMessageDeliveryStatus:(SCSUserTextEvent *)message;

/**
 Tells the delegate when the menu item has been selected.

 @param menuEvent Info about the selected menu item.

 @see `SCSChatMenuSelectionEvent`
 @see `SCSChatSession`
 */
- (void)session:(id<SCSChatSession>)session didSelectMenuItem:(SCSChatMenuSelectionEvent *)menuEvent;

/**
 Tells the delegate when an incoming message has arrived.

 @param message Info about the incoming message.

 @see `SCSAgentTextEvent`
 @see `SCSChatSession`
 */
- (void)session:(id<SCSChatSession>)session didReceiveMessage:(SCSAgentTextEvent *)message;

/**
 Tells the delegate when a chatbot menu has been received from the org.

 @param menuEvent Info about the chatbot menu.

 @see `SCSChatBotMenuEvent`
 @see `SCSChatSession`
 */
- (void)session:(id<SCSChatSession>)session didReceiveChatBotMenu:(SCSChatBotMenuEvent *)menuEvent;

/**
 Tells the delegate when an agent requests a file transfer.

 @param fileTransferEvent Info about the file transfer request.

 @see `SCSFileTransferEvent`
 @see `SCSChatSession`
 */
- (void)session:(id<SCSChatSession>)session didReceiveFileTransferRequest:(SCSFileTransferEvent *)fileTransferEvent;

/**
 Tells the delegate when a transfer to an agent is initiated.

 @param session Info about the chat session.
 */
- (void)transferToButtonInitiatedWithSession:(id<SCSChatSession>)session;

/**
 Tells the delegate when a transfer to an agent is completed.

 @param session Info about the chat session.
 */
- (void)transferToButtonCompletedWithSession:(id<SCSChatSession>)session;

/**
 Tells the delegate when a transfer to an agent has failed.

 @param session Info about the chat session.
 @param error NSError containing details about the failure.
 */
- (void)transferToButtonFailedWithSession:(id<SCSChatSession>)session error:(NSError *)error;

@optional

/**
 Tells the delegate when an agent begins typing.

 @param session Info about the chat session.
 */
- (void)agentBeganTypingWithSession:(id<SCSChatSession>)session;

/**
 Tells the delegate when an agent finishes typing.

 @param session Info about the chat session.
 */
- (void)agentFinishedTypingWithSession:(id<SCSChatSession>)session;

/**
 Tells the delegate when a URL has been detected in a message.

 @param urlEvent Info about the detected URL.
 */
- (void)session:(id<SCSChatSession>)session didReceiveURL:(SCSURLEvent *)urlEvent;

@end
