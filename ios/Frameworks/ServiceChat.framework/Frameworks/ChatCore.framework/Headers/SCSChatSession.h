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

@class SCSChatActor;
@class SCSUserTextEvent;

@protocol SCSChatEvent;

/**
 Information related to a chat session. Use this object to inspect the details
 of a chat session, and to send user messages to the agent.
 */
@protocol SCSChatSession <NSObject>

/**
 *  Property to access the actors (agents and iOS users) currently in the session.
 *
 *  @see `SCSChatActor`
 */
@property (nonatomic, strong, readonly) NSArray<SCSChatActor*> *actors;

/**
 *  Property to access all events (messages, agent requests, transfers, etc) that have occurred in the session.
 *
 *  @see `SCSChatEvent`
 */
@property (nonatomic, strong, readonly) NSArray<id<SCSChatEvent>> *allEvents;

/**
 * The current queue position the user has while waiting for an agent.
 */
@property (nonatomic, assign, readonly) NSInteger queuePosition;

/**
 * The estimated wait time for the user while waiting for an agent.
 */
@property (nonatomic, assign, readonly) NSTimeInterval estimatedWaitTime;

/**
 *  Property to access and set the typing status of the iOS user
 */
@property (nonatomic, getter = isUserTyping) BOOL userTyping;

/**
 *  The unique session id for the chat session.
 */
@property (nonatomic, strong, readonly) NSString *sessionId;

/**
 *  The unique id representing the chat visitor.
 */
@property (nonatomic, strong, readonly) NSString *visitorId;

/**
 * Sends a sneak peek of the message to the agent.
 * The sneak peek contains content that the user has not officially sent to the agent but has recently typed.
 */
- (void)sendSneakPeek:(NSString *)message;

/**
 * Sends a message to an agent.
 */
- (void)sendMessage:(NSString *)message;

@end
