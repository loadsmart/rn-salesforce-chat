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
#import "SCCDefines.h"

NS_ASSUME_NONNULL_BEGIN


@class SCAppearanceConfiguration;

/* SCFontWeight */
SCS_EXTERN NSInteger const SCFontWeightLight;
SCS_EXTERN NSInteger const SCFontWeightRegular;
SCS_EXTERN NSInteger const SCFontWeightBold;

SCS_EXTERN CGFloat const SCNavigationBarButtonWidth;

/**
 Delegate protocol for responding to style and branding customization requests at runtime.
 */
@protocol SCAppearanceConfigurationDelegate <NSObject>

@optional

/**
 Tells the delegate when appearance configuration updates will be applied.
 
 @param configuration The appearance configuration to be applied.
 */
- (void)appearanceConfigurationWillApplyUpdates:(SCAppearanceConfiguration*)configuration;

/**
 Tells the delegate when appearance configuration updates have been applied.
 
 @param configuration The appearance configuration that was applied.
 */
- (void)appearanceConfigurationDidApplyUpdates:(SCAppearanceConfiguration*)configuration;

@end

/**
 Configuration class used to customize the settings that influence the branding
 and coloring of UI elements used throughout the SDK.
 
 Pass an instance of this class to the `SCServiceCloud.appearanceConfiguration`
 property on the `SCServiceCloud` shared instance to set the appearance.
 */
@interface SCAppearanceConfiguration : NSObject

/**
 The appearance delegate, used for branding customization.
 
 @see `SCAppearanceConfigurationDelegate`
 */
@property (nonatomic, weak, nullable) NSObject<SCAppearanceConfigurationDelegate> *delegate;

/**
 Property indicating whether any `UIAppearance` settings have been applied 
 from this configuration instance.
 */
@property (nonatomic, readonly, getter=isAppearanceApplied) BOOL appearanceApplied;

/**
 Controls whether the `UIAppearance` selectors need to be updated.

 @see `-applyAppearanceUpdatesIfNeeded`
 */
- (void)setNeedsAppearanceUpdates;

/**
 Updates the `UIAppearance` selectors to reflect the current state of the 
 configuration object.
 
 This method can be used to force appearance updates to occur at a particular 
 time, or if there is cause for some branding changes to be reapplied.  
 
 @note Updates are only applied if the appearance settings have indeed changed.
 
 @see `-setNeedsAppearanceUpdates`
 */
- (void)applyAppearanceUpdatesIfNeeded;

@end

@interface SCAppearanceConfiguration (Colors)

/**
 Sets the color for the named `SCAppearanceConfiguration` constant.

 @param color The color to set.
 @param name  The branding token name to set the color for.
 */
- (void)setColor:(UIColor*)color forName:(SCSAppearanceColorToken)name;

/**
 Returns the color set by the `-setColor:forName:` method for the named 
 `SCAppearanceConfiguration` constant.
 
 If no value has been specified, the default value is returned.
 
 @param name The branding token name to retrieve a color for.
 @return The color associated with that branding token, or `nil` 
         if the branding token name is invalid.
 */
- (nullable UIColor*)colorForName:(SCSAppearanceColorToken)name;

@end

@interface SCAppearanceConfiguration (Images)

/**
 Sets the image for a named `SCAppearanceConfiguration` constant.
 
 @param image           The image to set.
 @param traitCollection The trait collection the image will be used for, if applicable.
 @param name            The branding token name to set the image for.
 */
- (void)setImage:(UIImage*)image compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection forName:(SCSAppearanceImageToken)name NS_SWIFT_NAME(setImage(_:compatibleWithTraitCollection:forToken:));

/**
 Returns the image set by the `-setImage:compatibleWithTraitCollection:forName:` method for the
 named `SCAppearanceConfiguration` constant.
 
 If no value has been specified, the default value is returned.
 
 @param name            The image name to retrieve an image for.
 @param traitCollection The trait collection the image will be used for, 
                        if applicable.
 */
- (nullable UIImage*)imageForName:(SCSAppearanceImageToken)name compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection NS_SWIFT_NAME(image(forToken:compatibleWithTraitCollection:));

@end

@interface SCAppearanceConfiguration (Fonts)

/**
 Sets `fontDescriptor` for specified weight; used to create and set the 
 `UIFont` on the labels.
 
 If `UIFontDescriptorSizeAttribute` is set on the `fontDescriptor`, it is used 
 to set the font size. If not, the SDK sets the font size appropriately.
 
 @param fontDescriptor `UIFontDescriptor` instance to be used for creating `UIFont`.
 @param fileName Name of the font file contained in the bundle, or `nil` when using a built-in system font.
 @param weight A value from the `SCFontWeight` enum.
 */
- (void)setFontDescriptor:(UIFontDescriptor*)fontDescriptor fontFileName:(nullable NSString*)fileName forWeight:(NSInteger)weight;

/**
 Returns the `fontDescriptor` for the specified weight.
 
 If no value has been specified, the default value is returned.
 Default values:
 
 - `Helvetica Neue - Light` for `SCFontWeightLight`,
 - `Helvetica Neue` for `SCFontWeightRegular`,
 - `Helvetica Neue - Semibold` for `SCFontWeightBold`.

 @param weight A value from the `SCFontWeight` enum.
 */
- (UIFontDescriptor*)getFontDescriptorForWeight:(NSInteger)weight __deprecated_msg("Method deprecated. Use `getFontDescriptorForWeight:size:`");

/**
 Returns the `fontDescriptor` for the specified weight.

 If no value has been specified, the default value is returned.
 Default values:

 - `San Francisco` with `UIFontWeightThin` for `SCFontWeightLight`
 - `San Francisco` with `UIFontWeightRegular` for `SCFontWeightRegular`
 - `San Francisco` with `UIFontWeightSemibold` for `SCFontWeightBold`

 @param weight The font weight: `SCFontWeightLight`, `SCFontWeightRegular`, or `SCFontWeightBold`.
 @param size   Size of the desired font
 */
- (UIFontDescriptor*)getFontDescriptorForWeight:(NSInteger)weight size:(CGFloat)size;

/**
 Gets the font filename for a given weight.
 
 @param weight The font weight: `SCFontWeightLight`, `SCFontWeightRegular`, or `SCFontWeightBold`.
 @return The font filename.
 */
- (nullable NSString*)getFontFileNameForWeight:(NSInteger)weight;

@end

@interface SCAppearanceConfiguration (AttributedText)

/**
 Sets the attributed text attributes for the named `SCAppearanceConfiguration` constant.

 @param attributes      The text attributes to set.
 @param traitCollection The trait collection these attributes will be used for, if applicable.
 @param name            The branding token name to set the attributes for.
 */
- (void)setTextAttributes:(NSDictionary<NSString *, id>*)attributes compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection forName:(SCSAppearanceLabelToken)name;

/**
 Returns the text attribute set by the `-setTextAttributes:compatibleWithTraitCollection:forName:`
 method for the named `SCAppearanceConfiguration` constant.
 
 If no value has been specified, the default value is returned.

 @param name            The branding token name to retrieve the attributes for.
 @param traitCollection The trait collection these attributes will be used for, if applicable.
 */
- (nullable NSDictionary<NSString *, id>*)textAttributesForName:(SCSAppearanceLabelToken)name compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection;

@end

NS_ASSUME_NONNULL_END

