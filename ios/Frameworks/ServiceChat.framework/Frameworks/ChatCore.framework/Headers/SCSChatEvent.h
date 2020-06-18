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

#import "SCSChatActor.h"

/**
 Defines the type of actors associated with a chat event.
 */
typedef NS_ENUM(NSUInteger, SCSChatEventType) {
    /// Event type responsible for all information messages.
    SCSChatEventTypeInformation,
    
    /// Event type responsible for all user messages in the conversation.
    SCSChatEventTypeOutput,
    
    /// Event type responsible for agent responses in the conversation.
    SCSChatEventTypeInput
};

/**
 Information related to a chat event.
 Other chat event classes implement this protocol.
 */
@protocol SCSChatEvent <NSObject>

/**
 Date for this event.
 */
@property (nonatomic, strong, readonly, nonnull) NSDate *date;

/**
 The actor for this event.
 Not all events have an actor.
 */
@property (nonatomic, strong, readonly, nullable) SCSChatActor *sender;

/**
 The type of event.
 */
@property (nonatomic, assign, readonly) SCSChatEventType type;

@end

/**
 Information related to all events that are sent or received.
 */
@interface SCSChatEvent : NSObject <SCSChatEvent>

/**
 The date the event was created.
 */
@property (nonatomic, strong, readonly, nonnull) NSDate *date;

/**
 The actor that sent the event.

 @see `SCSChatActor`
 */
@property (nonatomic, strong, readonly, nullable) SCSChatActor *sender;

/**
 The type of event.
 
 @see `SCSChatEventType`
 */
@property (nonatomic, assign, readonly) SCSChatEventType type;

@end
