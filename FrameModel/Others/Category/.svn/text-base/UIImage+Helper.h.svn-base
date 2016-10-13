//
//  UIImage+Helper.h
//  english
//
//  Created by dou7 on 14-6-13.
//  Copyright (c) 2014年 dou7. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "UIImage+TinColor.h"
//#import "UIImage+Blur.h"
//#import "UIImage+ImageWithColor.h"
//#import "UIImage+Screenshot.h"
//#import "UIImage+Rotate.h"

@interface UIImage (Helper)

-(float) width;

-(float) height;

-(UIImage *) resize:(CGFloat)scale;

- (UIImage *)Resize:(CGSize)size;

- (UIImage*)transformWidth:(CGFloat)width height:(CGFloat)height;

/**
 *	@brief	merge image
 *
 *	@param 	icon 	the small icon image to merge in center
 *	@param 	size 	meger size
 *
 *	@return	merged image
 */
- (UIImage *)mergeImage:(UIImage *)icon size:(CGSize)size;

/**
 *	@brief	generate qr code
 *
 *	@param 	code 	info string
 *	@param 	size 	image size
 *
 *	@return	the info qr code image
 */
+ (UIImage *)generateQRCode:(NSString *)code size:(CGSize)size;

+ (UIImage *)createNonInterpolatedUIImageFormCIImage:(CIImage *)image withSize:(CGFloat) size;

// 压缩 指定大小的kb 图片
+ (UIImage *)compressImage:(UIImage *)image toMaxFileSize:(NSInteger)maxFileSize;

@end
