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
#import "SCSPrechatObject.h"

@class SCSPrechatPickerOption;

/**
 An `SCSPrechatPickerObject` specifies a pre-chat picker field that is
 displayed before a chat session is initiated.

 Use the `SCSPrechatPickerObject.required` property to specify whether this 
 field must have an option selected before initiating a session.

 To send data directly to the agent without user input, see `SCSPrechatObject`.

 This object must be added to your chat configuration using 
 `SCSChatConfiguration.prechatFields`.
 */
@interface SCSPrechatPickerObject : SCSPrechatObject

///---------------------------------
/// @name Properties
///---------------------------------

/**
 Determines if the field must have an option before the pre-chat form can be submitted.
 */
@property (nonatomic, getter=isRequired) BOOL required;

/**
 An array of `SCSPrechatPickerOption` for the user to select from in the pre-chat form.
 */
@property (nonatomic, copy, readonly) NSArray<SCSPrechatPickerOption*> *options;

///---------------------------------
/// @name Initialization
///---------------------------------

/**
 Instantiates an `SCSPrechatPickerObject` object for use with `SCSChatConfiguration.prechatFields`.
 This object will be displayed in the pre-chat window for the user to select a value.

 @param label    The identifying label to show to the agent in the Service Console.
 @param options  An array of `SCSPrechatPickerOption` for the user to select from in the pre-chat form.
 @return The `SCSPrechatPickerObject` instance.
 */
- (instancetype)initWithLabel:(NSString *)label options:(NSArray<SCSPrechatPickerOption*>*)options NS_DESIGNATED_INITIALIZER;

/// :nodoc:
- (instancetype)initWithLabel:(NSString *)label value:(NSString *)value UNAVAILABLE_ATTRIBUTE;

@end
