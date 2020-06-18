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
#import <UIKit/UIKit.h>
#import "SCSPrechatObject.h"

/**
 An `SCSPrechatTextInputObject` specifies a pre-chat text input field that is
 displayed before a chat session is initiated.

 Use the `SCSPrechatTextInputObject.required` property to specify whether
 this field must be filled in before initiating a session.

 To send data directly to the agent without user input, see `SCSPrechatObject`.

 This object must be added to your chat configuration using 
 `SCSChatConfiguration.prechatFields`.
 */
@interface SCSPrechatTextInputObject : SCSPrechatObject

///---------------------------------
/// @name Properties
///---------------------------------

/**
 Determines if the field must be filled before the pre-chat form can be submitted.
 */
@property (nonatomic, getter=isRequired) BOOL required;

/**
 Sets a maximum length for the text entered in the pre-chat field.
 */
@property (nonatomic) NSUInteger maxLength;

/**
 The keyboard type to be used for the field.
 */
@property (nonatomic) UIKeyboardType keyboardType;

/**
 The autocapitalization behaviour for the field.
 */
@property (nonatomic) UITextAutocapitalizationType autocapitalizationType;

/**
 The autocorrection behaviour for the field.
 */
@property (nonatomic) UITextAutocorrectionType autocorrectionType;

/**
 The inital value for the field.
 */
@property (nonatomic, copy) NSString *initialValue;

///---------------------------------
/// @name Initialization
///---------------------------------

/**
 Instantiates an `SCSPrechatTextInputObject` object for use with `SCSChatConfiguration.prechatFields`.
 This object will be displayed in the pre-chat window for the user to fill out.

 @param label    The identifying label to show to the agent in the Service Console.
 @return The `SCSPrechatTextInputObject` instance.
 */
- (instancetype)initWithLabel:(NSString *)label NS_DESIGNATED_INITIALIZER;

/// :nodoc:
- (instancetype)initWithLabel:(NSString *)label value:(NSString *)value UNAVAILABLE_ATTRIBUTE;

@end
