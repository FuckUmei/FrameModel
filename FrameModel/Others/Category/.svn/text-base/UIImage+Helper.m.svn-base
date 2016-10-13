//
//  UIImage+Helper.m
//  english
//
//  Created by dou7 on 14-6-13.
//  Copyright (c) 2014年 dou7. All rights reserved.
//

#import "UIImage+Helper.h"

@implementation UIImage (Helper)

-(float) width
{
   float w = CGImageGetWidth(self.CGImage);
    return w;
}

-(float) height
{
    float h = CGImageGetHeight(self.CGImage);
    return h;
}

-(UIImage *) resize:(CGFloat)scale
{
    return [UIImage imageWithCGImage:self.CGImage scale:scale orientation:UIImageOrientationUp];
}

- (UIImage *)Resize:(CGSize)size{
    // 创建一个bitmap的context
    // 并把它设置成为当前正在使用的context
    UIGraphicsBeginImageContext(size);
    // 绘制改变大小的图片
    [self drawInRect:CGRectMake(0, 0, size.width, size.height)];
    // 从当前context中创建一个改变大小后的图片
    UIImage* scaledImage = UIGraphicsGetImageFromCurrentImageContext();
    // 使当前的context出堆栈
    UIGraphicsEndImageContext();
    // 返回新的改变大小后的图片
    return scaledImage;
}
// --------------------------------------------------

// Resize an image

// --------------------------------------------------

- (UIImage*)transformWidth:(CGFloat)width height:(CGFloat)height {
    
    CGFloat destW = width;
    CGFloat destH = height;
    CGFloat sourceW = width;
    CGFloat sourceH = height;
    CGImageRef imageRef = self.CGImage;
    CGContextRef bitmap = CGBitmapContextCreate(NULL,destW,destH,CGImageGetBitsPerComponent(imageRef),4*destW,CGImageGetColorSpace(imageRef),(kCGBitmapByteOrder32Little | kCGImageAlphaPremultipliedFirst));
    CGContextDrawImage(bitmap, CGRectMake(0, 0, sourceW, sourceH), imageRef);
    CGImageRef ref = CGBitmapContextCreateImage(bitmap);
    UIImage *resultImage = [UIImage imageWithCGImage:ref];
    CGContextRelease(bitmap);
    CGImageRelease(ref);
    return resultImage;
}

#pragma mark - 生成条形码以及二维码

// 参考文档
// https://developer.apple.com/library/mac/documentation/GraphicsImaging/Reference/CoreImageFilterReference/index.html

+ (UIImage *)generateQRCode:(NSString *)code size:(CGSize)size {
    
    // 生成二维码图片
    CIImage *qrcodeImage;
    NSData *data = [code dataUsingEncoding:NSISOLatin1StringEncoding allowLossyConversion:false];
    CIFilter *filter = [CIFilter filterWithName:@"CIQRCodeGenerator"];
    
    [filter setValue:data forKey:@"inputMessage"];
    [filter setValue:@"H" forKey:@"inputCorrectionLevel"];
    qrcodeImage = [filter outputImage];
    // 消除模糊
//    CGFloat scaleX = size.width / qrcodeImage.extent.size.width; // extent 返回图片的frame
//    CGFloat scaleY = size.height / qrcodeImage.extent.size.height;
//    CIImage *transformedImage = [qrcodeImage imageByApplyingTransform:CGAffineTransformScale(CGAffineTransformIdentity, scaleX, scaleY)];

    return [self createNonInterpolatedUIImageFormCIImage:qrcodeImage withSize:200];
//    return  [UIImage imageWithCIImage:transformedImage];
}

#pragma mark - Public Methods
- (UIImage *)mergeImage:(UIImage *)icon size:(CGSize)size {
    if (!icon) {
        return self;
    }
    CGFloat t_corner = 4;
    CGSize t_size = self.size;
    CGSize s_size = icon.size;
    CGRect infoRect ;
    infoRect.origin = CGPointZero;
    infoRect.size = t_size;
    CGRect iconRect ;
    iconRect.origin = CGPointMake((t_size.width-size.width)*0.5, (t_size.height-size.height)*0.5);
    iconRect.size = size;
    icon = [self createRoundedRectImage:icon withSize:s_size withRadius:t_corner];
    UIBezierPath *path = [UIBezierPath bezierPathWithRoundedRect:iconRect cornerRadius:t_corner];
    iconRect = CGRectInset(iconRect, 3, 3);
    UIGraphicsBeginImageContextWithOptions(t_size, true, 1.0);
    
    [self drawInRect:infoRect];
    
    [[UIColor whiteColor] setFill];
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    CGContextAddPath(ctx, path.CGPath);
    CGContextClosePath(ctx);
    CGContextFillPath(ctx);
    
    [icon drawInRect:iconRect];
    
    UIImage *dstImg = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return dstImg;
}

#pragma mark - 私有 Methods
- (UIImage *)createRoundedRectImage:(UIImage *)image withSize:(CGSize)size withRadius:(NSInteger)radius {
    int w = size.width;
    int h = size.height;
    
    CGColorSpaceRef colorSpaceRef = CGColorSpaceCreateDeviceRGB();
    CGContextRef contextRef = CGBitmapContextCreate(NULL, w, h, 8, 4 * w, colorSpaceRef, (CGBitmapInfo)kCGImageAlphaPremultipliedLast);
    CGRect rect = CGRectMake(0, 0, w, h);
    
    CGContextBeginPath(contextRef);
    addRoundedRectToPath(contextRef, rect, radius, radius);
    CGContextClosePath(contextRef);
    CGContextClip(contextRef);
    CGContextDrawImage(contextRef, CGRectMake(0, 0, w, h), image.CGImage);
    CGImageRef imageMasked = CGBitmapContextCreateImage(contextRef);
    UIImage *img = [UIImage imageWithCGImage:imageMasked];
    
    CGContextRelease(contextRef);
    CGColorSpaceRelease(colorSpaceRef);
    CGImageRelease(imageMasked);
    return img;
}

static void addRoundedRectToPath(CGContextRef contextRef, CGRect rect, float widthOfRadius, float heightOfRadius) {
    float fw, fh;
    if (widthOfRadius == 0 || heightOfRadius == 0)
    {
        CGContextAddRect(contextRef, rect);
        return;
    }
    
    CGContextSaveGState(contextRef);
    CGContextTranslateCTM(contextRef, CGRectGetMinX(rect), CGRectGetMinY(rect));
    CGContextScaleCTM(contextRef, widthOfRadius, heightOfRadius);
    fw = CGRectGetWidth(rect) / widthOfRadius;
    fh = CGRectGetHeight(rect) / heightOfRadius;
    
    CGContextMoveToPoint(contextRef, fw, fh/2);  // Start at lower right corner
    CGContextAddArcToPoint(contextRef, fw, fh, fw/2, fh, 1);  // Top right corner
    CGContextAddArcToPoint(contextRef, 0, fh, 0, fh/2, 1); // Top left corner
    CGContextAddArcToPoint(contextRef, 0, 0, fw/2, 0, 1); // Lower left corner
    CGContextAddArcToPoint(contextRef, fw, 0, fw, fh/2, 1); // Back to lower right
    
    CGContextClosePath(contextRef);
    CGContextRestoreGState(contextRef);
}

/**
 *  根据CIImage生成指定大小的UIImage
 *
 *  @param image CIImage
 *  @param size  图片宽度
 */
+ (UIImage *)createNonInterpolatedUIImageFormCIImage:(CIImage *)image withSize:(CGFloat) size
{
    CGRect extent = CGRectIntegral(image.extent);
    CGFloat scale = MIN(size/CGRectGetWidth(extent), size/CGRectGetHeight(extent));
    
    // 1.创建bitmap;
    size_t width = CGRectGetWidth(extent) * scale;
    size_t height = CGRectGetHeight(extent) * scale;
    CGColorSpaceRef cs = CGColorSpaceCreateDeviceGray();
    CGContextRef bitmapRef = CGBitmapContextCreate(nil, width, height, 8, 0, cs, (CGBitmapInfo)kCGImageAlphaNone);
    CIContext *context = [CIContext contextWithOptions:nil];
    CGImageRef bitmapImage = [context createCGImage:image fromRect:extent];
    CGContextSetInterpolationQuality(bitmapRef, kCGInterpolationNone);
    CGContextScaleCTM(bitmapRef, scale, scale);
    CGContextDrawImage(bitmapRef, extent, bitmapImage);
    
    // 2.保存bitmap到图片
    CGImageRef scaledImage = CGBitmapContextCreateImage(bitmapRef);
    CGContextRelease(bitmapRef);
    CGImageRelease(bitmapImage);
    return [UIImage imageWithCGImage:scaledImage];
}

// 压缩 指定大小的kb 图片
+ (UIImage *)compressImage:(UIImage *)image toMaxFileSize:(NSInteger)maxFileSize {
    CGFloat compression = 0.9f;
    CGFloat maxCompression = 0.1f;
    NSData *imageData = UIImageJPEGRepresentation(image, compression);
    while ([imageData length] > maxFileSize && compression > maxCompression) {
        compression -= 0.1;
        imageData = UIImageJPEGRepresentation(image, compression);
    }
    
    UIImage *compressedImage = [UIImage imageWithData:imageData];
    return compressedImage;
}

@end
