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

/**
 *  Reasons why a chat session may have ended.
 *
 *  @see `SCSChatSessionEndEvent`
 */
typedef NS_ENUM(NSInteger, SCSChatEndReason) {
    /**
     *  Session was ended due to user interaction.
     */
    SCSChatEndReasonUser = 1,

    /**
     * Session was ended remotely by the agent.
     */
    SCSChatEndReasonAgent,

    /**
     * Session was ended as a result of no agents being available.
     */
    SCSChatEndReasonNoAgentsAvailable,

    /**
     * Session was ended due to a network disruption resulting in a timeout.
     */
    SCSChatEndReasonTimeout,

    /**
     * Session was ended as the result of a fatal error.
     */
    SCSChatEndReasonSessionError,
};
