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
 *  Live Agent Chat ErrorCode definitions.
 *
 *  Errors fall into one of several groups (or series) of errors.
 *
 *  If there is an error thrown by a library dependency it will be included as metadata
 *  in the userInfo of the error which is returned to the application code.
 *
 *  @see `-[SCSChatSessionDelegate session:didError:fatal:]`
 *  @see `-[SCSChatSessionDelegate session:didEndWithReason:]`
 */
typedef NS_ENUM(NSInteger, SCSChatErrorCode) {
    ///--------------------------------
    /// @name General Errors (1000-series)
    ///--------------------------------

    /**
     *  Unclassified error. This results from an unknown or unexpected error state.
     *
     *  Any other un-grouped errors will be added to the 1000 series error group.
     */
    SCSChatGenericError = 1000,

    /**
     *  The <SCSChatConfiguration> object provided to the <SCSChat> is invalid.
     */
    SCSChatInvalidConfiguration = 1001,

    /**
     *  Another session is already in progress
     */
    SCSChatExistingSessionError = 1002,

    ///--------------------------------
    /// @name Connection Errors (2000-series)
    ///--------------------------------

    /**
     *  Standard communication error. This can be returned from operations dependent on communication
     *  between Live Agent or any other remote system.
     *
     *  All communication related errors will be found in the 2000 series error group.
     */
    SCSChatCommunicationError = 2000,

    /**
     *  Returned when attempting to start a session when no agents are available to accept the request.
     */
    SCSChatNoAgentsAvailableError = 2001,

    /**
     *  Returned when attempting to start a session and a network error occurs.
     */
    SCSChatSessionCreationError = 2002,

    /**
     *  Returned when attempting to perform an action in an established session and a network error occurs.
     */
    SCSChatSessionEventError = 2003,

    ///--------------------------------
    /// @name File Transfer Errors (3000-series)
    ///--------------------------------

    /**
     * Returned when an attempted file transfer fails.
     */
    SCSChatFileTransferError = 3000
};
