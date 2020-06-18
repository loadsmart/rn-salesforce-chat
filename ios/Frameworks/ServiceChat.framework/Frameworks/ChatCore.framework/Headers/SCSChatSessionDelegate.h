/*
 * Copyright 2016 salesforce.com, inc.
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
#import "SCSChatSession.h"
#import "SCSChatSessionState.h"
#import "SCSChatCoreDefines.h"
#import "SCSChatEndReason.h"

@class SCSChat;
@class SCSChatSessionEndEvent;

/**
 The `SCSChatSessionDelegate` protocol provides state information about the chat
 session. Add your implementation to `-[SCSChat addDelegate:]`.

 @see `SCSChatSession`
 @see `SCSChat`
 @see `SCSChatEventDelegate`
 */
@protocol SCSChatSessionDelegate <NSObject>

@required

/**
 Tells the delegate an error was raised during a chat session.

 @param session  `SCSChatSession` instance which invoked the error.
 @param error `NSError` instance describing the error.
 Error codes can be referenced from `SCSChatErrorCode`.
 @param fatal Indicates whether the error resulted in the termination of a session.

 @see `SCSChatSession`
 */
- (void)session:(id<SCSChatSession>)session didError:(NSError *)error fatal:(BOOL)fatal;


@optional

/**
 Tells the delegate when a chat session ends.

 @param session   `SCSChatSession` instance which invoked the method.
 @param endEvent `SCSChatSessionEndEvent` describing why the session has ended.
 Error codes can be referenced from `SCSChatErrorCode`.
  
 @see `SCSChatSession`
 @see `SCSChatSessionEndEvent`
 */
- (void)session:(id<SCSChatSession>)session didEnd:(SCSChatSessionEndEvent *)endEvent;

/**
 Tells the delegate when the chat session state has changed.

 @param session   `SCSChatSession` instance which invoked the method.
 @param previous `SCSChatSessionState` previous state.
 @param current `SCSChatSessionState` current state.
 
 @see `SCSChatSession`
 @see `SCSChatSessionState`
 */
- (void)session:(id<SCSChatSession>)session didTransitionFromState:(SCSChatSessionState)previous toState:(SCSChatSessionState)current;

/**
 Tells the delegate when the user's position in the agent queue has changed.
 
 @param session        `SCSChatSession` instance which invoked the method.
 @param position    `NSNumber` instance representing position in the queue.
 @param waitTime    `NSNumber` instance representing estimated wait time, in seconds.

 @see `SCSChatSession`
 */
- (void)session:(id<SCSChatSession>)session didUpdateQueuePosition:(NSNumber *)position estimatedWaitTime:(NSNumber *)waitTime;

/**
 Tells the delegate when the user's position in the agent queue has changed.

 @param session        `SCSChatSession` instance which invoked the method.
 @param position    `NSNumber` instance representing position in the queue.

 @see `SCSChatSession`
 */
- (void)session:(id<SCSChatSession>)session didUpdateQueuePosition:(NSNumber *)position __API_DEPRECATED_WITH_REPLACEMENT("session:didUpdateQueuePosition:estimatedWaitTime", ios(1.0,100.0));

@end

