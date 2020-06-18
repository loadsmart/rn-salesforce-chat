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

#import "SCSChatSendableEvent.h"

/**
 *  The types of message modifications that are possible due to sensitive data rules.
 */
typedef NS_ENUM(NSUInteger, SCUserEventInfoType) {

    /**
     *  Standard message.
     */
    SCUEInfoTypeNone,

    /**
     *  Message modified by sensitive data rule.
     */
    SCUEInfoTypeModified,

    /**
     *  Message fully redacted by sensitive data rule.
     */
    SCUEInfoTypeRedacted
};

/**
 *  The types of message modifications that are possible due to sensitive data rules.
 */
typedef NS_ENUM(NSUInteger, SCSUserEventDeliveryStatus) {

    /**
     *  Delivery status is unknown. This is the default state when the event is created.
     */
    SCSUserEventDeliveryStatusUnknown,

    /**
     *  Message has been delivered.
     */
    SCSUserEventDeliveryStatusDelivered,

    /**
     *  Delivery of this message has failed.
     */
    SCSUserEventDeliveryStatusFailed
};

/**
 Information about a user text event.
 
 @see `SCSChatSendableEvent`
 */
@interface SCSUserTextEvent : SCSChatEvent <SCSChatSendableEvent>

/**
 The text of the original user message.
 */
@property (nonatomic, copy, readonly) NSString *originalText;

/**
 The text of the outgoing user message.
 */
@property (nonatomic, copy, readonly) NSString *text;

/**
 Details describing if and how the outgoing message was modified.
 
 @see `SCUserEventInfoType`
 */
@property (nonatomic, assign, readonly) SCUserEventInfoType infoType;

/**
 Indicates whether the text event has completed.
 */
@property (nonatomic, readonly, getter=isCompleted) BOOL completed DEPRECATED_MSG_ATTRIBUTE("Use deliveryStatus instead.");

/**
 The current delivery status of the event.
 */
@property (nonatomic, assign, readonly) SCSUserEventDeliveryStatus deliveryStatus;

@end
