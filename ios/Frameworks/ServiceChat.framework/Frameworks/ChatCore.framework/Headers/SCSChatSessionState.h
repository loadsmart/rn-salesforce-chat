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
 * Complete list of chat session states.
 *
 * @see `-[SCSChatSessionDelegate session:didTransitionFromState:toState:]`
 */
typedef NS_ENUM(NSUInteger, SCSChatSessionState) {
    /**
     *  No active session. There will be no outgoing/incoming chat traffic.
     */
    SCSChatSessionStateInactive,

    /**
     *  A connection with Live Agent servers is being established.
     */
    SCSChatSessionStateConnecting,

    /**
     *  A connection has been established, but queueing for next available agent.
     */
    SCSChatSessionStateQueued,

    /**
     *  Connected with an agent to facilitate a chat session.
     */
    SCSChatSessionStateConnected,

    /**
     *  Session is in the process of cleaning up network connections and ending.
     */
    SCSChatSessionStateEnding,
};
