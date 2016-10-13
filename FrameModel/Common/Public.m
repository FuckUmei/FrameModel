//
//  Public.m
//  FrameModel
//
//  Created by specter on 16/10/12.
//  Copyright © 2016年 specter. All rights reserved.
//

#import "Public.h"
#import "AppDelegate.h"
#import <Accelerate/Accelerate.h>
#import <AudioToolbox/AudioToolbox.h>
#import "sys/utsname.h"


@interface Public ()
{
    UIView * back;// 送餐, 快递背景
    UIView * blackView;// 黑色遮罩
}
@end

@implementation Public

+ (CGFloat)deviceWidth:(CGFloat)width
{
    AppDelegate *myDelegate = [AppDelegate shareDelegate];
    
    return width * myDelegate.autoSizeScaleX;
}

+ (CGFloat)deviceHeight:(CGFloat)height
{
    AppDelegate *myDelegate = [AppDelegate shareDelegate];
    
    return height * myDelegate.autoSizeScaleY;
}

+ (Public *)shared
{
    static Public * public = nil;
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        public = [[Public alloc]init];
    });
    return public;
}

#pragma mark -
#pragma mark 颜色渐变
+ (CAGradientLayer*) greyGradient {
    UIColor *colorOne = [UIColor colorWithRed:0.008 green:0.010 blue:0.009 alpha:1];
    UIColor *colorTwo = [UIColor colorWithWhite:0.220 alpha:1];
    UIColor *colorThree = [UIColor colorWithWhite:0.288 alpha:1];
    UIColor *colorFour = [UIColor colorWithRed:0.008 green:0.010 blue:0.009 alpha:1];
    
    
    
    NSArray *colors =  [NSArray arrayWithObjects:(id)colorOne.CGColor, colorTwo.CGColor, colorThree.CGColor, colorFour.CGColor, nil];
    NSNumber *stopOne = [NSNumber numberWithFloat:0.0];
    NSNumber *stopTwo = [NSNumber numberWithFloat:0.1];
    NSNumber *stopThree     = [NSNumber numberWithFloat:0.2];
    NSNumber *stopFour = [NSNumber numberWithFloat:1.0];
    NSArray *locations = [NSArray arrayWithObjects:stopOne, stopTwo, stopThree, stopFour, nil];
    CAGradientLayer *headerLayer = [CAGradientLayer layer];
    headerLayer.colors = colors;
    headerLayer.locations = locations;
    return headerLayer;
}
//Blue gradient background
+ (CAGradientLayer*) blueGradient {
    UIColor *colorOne = [UIColor colorWithRed:(120/255.0) green:(135/255.0) blue:(150/255.0) alpha:1.0];
    UIColor *colorTwo = [UIColor colorWithRed:(57/255.0)  green:(79/255.0)  blue:(96/255.0)  alpha:1.0];
    NSArray *colors = [NSArray arrayWithObjects:(id)colorOne.CGColor, colorTwo.CGColor, nil];
    NSNumber *stopOne = [NSNumber numberWithFloat:0.0];
    NSNumber *stopTwo = [NSNumber numberWithFloat:1.0];
    NSArray *locations = [NSArray arrayWithObjects:stopOne, stopTwo, nil];
    CAGradientLayer *headerLayer = [CAGradientLayer layer];
    headerLayer.colors = colors;
    headerLayer.locations = locations;
    return headerLayer;
}

+ (UIButton *)creatBackButton
{
    UIImage * image = [UIImage imageNamed:@"buttonBack"];
    UIButton * button = [[UIButton alloc]initWithFrame:CGRectMake(0, 0, image.size.width/3, image.size.height/3)];
    [button setImage:image forState:UIControlStateNormal];
    return button;
}

+ (void)createNavigationLeftBarButtonItemWithCustomView:(UIButton *)myButton andNavItem:(UINavigationItem *)item
{
    UIBarButtonItem *buttonItem = [[UIBarButtonItem alloc] initWithCustomView:myButton];
    if ([[[[UIDevice currentDevice] systemVersion] substringToIndex:1] intValue]>=7) {
        UIBarButtonItem *negativeSpacer = [[UIBarButtonItem alloc]initWithBarButtonSystemItem:UIBarButtonSystemItemFixedSpace target:nil action:nil];
        negativeSpacer.width = -5;
        item.leftBarButtonItems = @[negativeSpacer, buttonItem];
    }else{
        item.leftBarButtonItem = buttonItem;
    }
}



+ (UIColor *)returnWrightColor
{
    UIColor * color = [UIColor colorWithRed:0.000 green:0.678 blue:0.878 alpha:1.000];
    return color;
}

+ (UILabel *)returnTitleView:(NSString *)title andColor:(UIColor *)color andFount:(CGFloat)fount
{
    UILabel * label = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, 100, 30)];
    [label setText:title];
    [label setFont:[UIFont boldSystemFontOfSize:fount]];
    [label setTextColor:color];
    [label setTextAlignment:NSTextAlignmentCenter];
    return label;
}


+ (void)soundPlay:(NSString *)name
{
    if ([name isEqualToString:@"system"]) {
            NSString * soundName = @"sms-received1";
            NSString * soundType = @"caf";
        SystemSoundID sound;//系统声音的id 取值范围为：1000-2000
        //
            NSString *path = [NSString stringWithFormat:@"/System/Library/Audio/UISounds/%@.%@",soundName,soundType];
        
        
//        NSString *path = [[NSBundle mainBundle] pathForResource:name ofType:@"wav"];
        //      [[NSBundle mainBundle] URLForResource: @"eat" withExtension: @"wav"];  获取自定义的声音
        if (path) {
            OSStatus error = AudioServicesCreateSystemSoundID((__bridge CFURLRef)[NSURL fileURLWithPath:path],&sound);
            
            if (error != kAudioServicesNoError)
            {
                //获取的声音的时候，出现错误
                sound = error;
            }
        }
        AudioServicesPlaySystemSound(sound);

    }
    else
    {
        //NSString * soundName = @"sms-received1";
        //    NSString * soundType = @"caf";
        SystemSoundID sound;//系统声音的id 取值范围为：1000-2000
        //
        //    NSString *path = [NSString stringWithFormat:@"/System/Library/Audio/UISounds/%@.%@",soundName,soundType];
        
        
        NSString *path = [[NSBundle mainBundle] pathForResource:name ofType:@"wav"];
        //      [[NSBundle mainBundle] URLForResource: @"eat" withExtension: @"wav"];  获取自定义的声音
        if (path) {
            OSStatus error = AudioServicesCreateSystemSoundID((__bridge CFURLRef)[NSURL fileURLWithPath:path],&sound);
            
            if (error != kAudioServicesNoError)
            {
                //获取的声音的时候，出现错误
                sound = error;
            }
        }
        AudioServicesPlaySystemSound(sound);

    }

    

}

+ (void)shakePlay
{
    SystemSoundID sound;//系统声音的id 取值范围为：1000-2000

    sound = kSystemSoundID_Vibrate;//震动
    AudioServicesPlaySystemSound(sound);
}

/**
 *  系统当前时间
 *
 *  @return 返回时间字符串
 */
+ (NSString *)currentTime
{
    NSDate *  senddate = [NSDate date];
    NSDateFormatter  *dateformatter = [[NSDateFormatter alloc] init];
    [dateformatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
    NSString *  locationString = [dateformatter stringFromDate:senddate];
//    NSLog(@"locationString:%@",locationString);
    return locationString;

}

+ (NSString *)returnTime:(NSString *)time
{
    if (time != nil) {
        if ([time length] == 1) {
            NSString * reTime = [NSString stringWithFormat:@"0%@",time];
            return reTime;
        }
    }
    return time;
    
}

+ (NSDate *)returnDate:(NSString *)time
{
    NSDateFormatter* formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"yyyyMMddHHMMss"];
    NSDate *date = [formatter dateFromString:time];
    return date;
}

+ (NSString *)currentTimeforData:(NSString *)strtime
{
    NSDate *senddate = [self returnDate:strtime];
    NSDateFormatter  *dateformatter = [[NSDateFormatter alloc] init];
    [dateformatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
    NSString *  locationString = [dateformatter stringFromDate:senddate];
    //    NSLog(@"locationString:%@",locationString);
    return locationString;
}

+ (void)showAlertTitle:(NSString *)title message:(NSString *)message delegate:(id)delegate
{
    UIAlertView * alert = [[UIAlertView alloc]initWithTitle:title message:message delegate:delegate cancelButtonTitle:@"确认" otherButtonTitles: nil];
    [alert show];
}

+ (NSMutableArray *)arrayRemoveDuplicate:(NSArray *)array
{
    //去重
    NSMutableArray *categoryArray = [[NSMutableArray alloc] init];
    for (unsigned i = 0; i < [array count]; i++){
        if ([categoryArray containsObject:[array objectAtIndex:i]] == NO){
            [categoryArray addObject:[array objectAtIndex:i]];
        }
        
    }
    return categoryArray;
}


+ (CGFloat)originAndHeight:(UIView *)widget
{
    return widget.frame.origin.y + widget.frame.size.height;
}

+ (CGFloat)originAndWeight:(UIView *)widget
{
    return widget.frame.origin.x + widget.frame.size.width;
}


//+ (void)waitingStart
//{
//    [MBProgressHUD showHUDAddedTo:[[UIApplication sharedApplication] windows][0] animated:YES];
//}
//+ (void)waitingStop
//{
//    [MBProgressHUD hideAllHUDsForView:[[UIApplication sharedApplication] windows][0] animated:YES];
//}

// 模糊 (毛玻璃)
+(UIImage *)gaussianBlue:(CGFloat)blur andImage:(UIImage *)image
{
    NSData *imageData = UIImageJPEGRepresentation(image, 1); // convert to jpeg
    UIImage* destImage = [UIImage imageWithData:imageData];
    
    
    if (blur < 0.f || blur > 1.f) {
        blur = 0.5f;
    }
    int boxSize = (int)(blur * 40);
    boxSize = boxSize - (boxSize % 2) + 1;
    
    CGImageRef img = destImage.CGImage;
    
    vImage_Buffer inBuffer, outBuffer;
    
    vImage_Error error;
    
    void *pixelBuffer;
    
    
    //create vImage_Buffer with data from CGImageRef
    
    CGDataProviderRef inProvider = CGImageGetDataProvider(img);
    CFDataRef inBitmapData = CGDataProviderCopyData(inProvider);
    
    
    inBuffer.width = CGImageGetWidth(img);
    inBuffer.height = CGImageGetHeight(img);
    inBuffer.rowBytes = CGImageGetBytesPerRow(img);
    
    inBuffer.data = (void*)CFDataGetBytePtr(inBitmapData);
    
    //create vImage_Buffer for output
    
    pixelBuffer = malloc(CGImageGetBytesPerRow(img) * CGImageGetHeight(img));
    
    if(pixelBuffer == NULL)
        NSLog(@"No pixelbuffer");
    
    outBuffer.data = pixelBuffer;
    outBuffer.width = CGImageGetWidth(img);
    outBuffer.height = CGImageGetHeight(img);
    outBuffer.rowBytes = CGImageGetBytesPerRow(img);
    
    // Create a third buffer for intermediate processing
    void *pixelBuffer2 = malloc(CGImageGetBytesPerRow(img) * CGImageGetHeight(img));
    vImage_Buffer outBuffer2;
    outBuffer2.data = pixelBuffer2;
    outBuffer2.width = CGImageGetWidth(img);
    outBuffer2.height = CGImageGetHeight(img);
    outBuffer2.rowBytes = CGImageGetBytesPerRow(img);
    
    //perform convolution
    error = vImageBoxConvolve_ARGB8888(&inBuffer, &outBuffer2, NULL, 0, 0, boxSize, boxSize, NULL, kvImageEdgeExtend);
    if (error) {
        NSLog(@"error from convolution %ld", error);
    }
    error = vImageBoxConvolve_ARGB8888(&outBuffer2, &inBuffer, NULL, 0, 0, boxSize, boxSize, NULL, kvImageEdgeExtend);
    if (error) {
        NSLog(@"error from convolution %ld", error);
    }
    error = vImageBoxConvolve_ARGB8888(&inBuffer, &outBuffer, NULL, 0, 0, boxSize, boxSize, NULL, kvImageEdgeExtend);
    if (error) {
        NSLog(@"error from convolution %ld", error);
    }
    
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    CGContextRef ctx = CGBitmapContextCreate(outBuffer.data,
                                             outBuffer.width,
                                             outBuffer.height,
                                             8,
                                             outBuffer.rowBytes,
                                             colorSpace,
                                             (CGBitmapInfo)kCGImageAlphaNoneSkipLast);
    CGImageRef imageRef = CGBitmapContextCreateImage (ctx);
    UIImage *returnImage = [UIImage imageWithCGImage:imageRef];
    
    //clean up
    CGContextRelease(ctx);
    CGColorSpaceRelease(colorSpace);
    
    free(pixelBuffer);
    free(pixelBuffer2);
    CFRelease(inBitmapData);
    
    CGImageRelease(imageRef);
    
    return returnImage;
}

- (void)OKButton
{
    [back removeFromSuperview];
    [blackView removeFromSuperview];
    self.publicBlock();
}

+ (NSString*)deviceString
{
    // 需要#import "sys/utsname.h"
    struct utsname systemInfo;
    uname(&systemInfo);
    NSString *deviceString = [NSString stringWithCString:systemInfo.machine encoding:NSUTF8StringEncoding];
  
    //iPhone
    if ([deviceString isEqualToString:@"iPhone1,1"])    return @"iPhone 1G";
    if ([deviceString isEqualToString:@"iPhone1,2"])    return @"iPhone 3G";
    if ([deviceString isEqualToString:@"iPhone2,1"])    return @"iPhone 3GS";
    if ([deviceString isEqualToString:@"iPhone3,1"])    return @"iPhone 4";
    if ([deviceString isEqualToString:@"iPhone3,2"])    return @"Verizon iPhone 4";
    if ([deviceString isEqualToString:@"iPhone4,1"])    return @"iPhone 4S";
    if ([deviceString isEqualToString:@"iPhone5,1"])    return @"iPhone 5";
    if ([deviceString isEqualToString:@"iPhone5,2"])    return @"iPhone 5";
    if ([deviceString isEqualToString:@"iPhone5,3"])    return @"iPhone 5C";
    if ([deviceString isEqualToString:@"iPhone5,4"])    return @"iPhone 5C";
    if ([deviceString isEqualToString:@"iPhone6,1"])    return @"iPhone 5S";
    if ([deviceString isEqualToString:@"iPhone6,2"])    return @"iPhone 5S";
    if ([deviceString isEqualToString:@"iPhone7,1"])    return @"iPhone 6 Plus";
    if ([deviceString isEqualToString:@"iPhone7,2"])    return @"iPhone 6";
    if ([deviceString isEqualToString:@"iPhone8,1"])    return @"iPhone 6s";
    if ([deviceString isEqualToString:@"iPhone8,2"])    return @"iPhone 6s Plus";
//    if ([deviceString isEqualToString:@"i386"])         return @"Simulator";
//    if ([deviceString isEqualToString:@"x86_64"])       return @"Simulator";
    NSLog(@"NOTE: Unknown device type: %@", deviceString);
    return deviceString;
}


#pragma mark -- 图片裁剪
+ (UIImage *)cutImage:(UIImage *)image frame:(CGRect)rect
{
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    // translated rectangle for drawing sub image
    CGRect drawRect = CGRectMake(-rect.origin.x, -rect.origin.y, image.size.width, image.size.height);
    
    // clip to the bounds of the image context
    // not strictly necessary as it will get clipped anyway?
    CGContextClipToRect(context, CGRectMake(0, 0, rect.size.width, rect.size.height));
    
    // draw image
    [image drawInRect:drawRect];
    
    // grab image
    UIImage* croppedImage = UIGraphicsGetImageFromCurrentImageContext();
    
    UIGraphicsEndImageContext();
    
    return croppedImage;
}

+ (NSString *)buildVersion
{
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    
    // app版本
    //    NSString *app_Version = [infoDictionary objectForKey:@"CFBundleShortVersionString"];
    
    // app build版本
    NSString *app_build = [infoDictionary objectForKey:@"CFBundleVersion"];
    
    return app_build;
}

+ (NSString*)DataTOjsonString:(id)object
{
    NSString *jsonString = nil;
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:object
                                                       options:NSJSONWritingPrettyPrinted // Pass 0 if you don't care about the readability of the generated string
                                                         error:&error];
    if (! jsonData) {
        NSLog(@"Got an error: %@", error);
    } else {
        jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
    }
    return jsonString;
}

// 将JSON串转化为字典或者数组
+ (id)toArrayOrNSDictionary:(NSString *)jsonString
{
    NSData *jsonData = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
    NSError *error = nil;
    id jsonObject = [NSJSONSerialization JSONObjectWithData:jsonData
                                                    options:NSJSONReadingAllowFragments
                                                      error:&error];
    
    if (jsonObject != nil && error == nil){
        return jsonObject;
    }else{
        // 解析错误
        return nil;
    }
    
}

+ (void)getBuglyLog
{
//    [Bugly startWithAppId:kBugly_AppId];// sdk 崩溃日志记录
//    [Bugly setUserValue:[self deviceString] forKey:@"设备型号 - "];
//    [Bugly setUserValue:[self buildVersion] forKey:@"build版本号 - "];
//    [Bugly setUserValue:[GlobalHelper GetObjectFromUDF:USER_NAME] forKey:@"用户名 - "];
}

@end
