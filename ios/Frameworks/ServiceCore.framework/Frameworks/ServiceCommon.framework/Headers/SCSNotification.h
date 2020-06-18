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
 A `SCSNotificationType` defines the type of notification.
 */
typedef NS_ENUM(NSInteger, SCSNotificationType) {
    /** Notification associated with a case. */
    SCSNotificationTypeCase = 1,
};

/**
 An `SCSNotification` object represents a push notification that was sent to the app
 from your Salesforce connected app.
 
 The `SCSNotification` class itself is an abstract class.
 Based on the `userInfo` dictionary passed to it from the push notification payload, a
 concrete subclass of `SCSNotification` is returned by calling:
 `-[SCServiceCloud notificationFromRemoteNotificationDictionary:]`
 */

@interface SCSNotification : NSObject

/**
 Use this property to find out the type of `SCSNotification` instead of using `isKindOfClass`.
 */
@property (nonatomic, readonly, assign) SCSNotificationType notificationType;

@end

/**
 Concrete subclass of `SCSNotification` representing a push notification for a case.
 */
@interface SCSCaseNotification : SCSNotification

/**
 The case ID for the notification.
 */
@property (nonatomic, strong, readonly) NSString *caseId;

/**
 Indicates whether or not this notification is referencing a specific case or not.
 */
@property (nonatomic, assign, readonly) BOOL referencesSpecificCase;

@end
