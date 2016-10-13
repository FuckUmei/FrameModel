//
//  NSString+AES256.h
//  OneShopKeeper
//
//  Created by DavyZhang on 16/8/5.
//  Copyright © 2016年 yihaozhanggui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonDigest.h>
#import <CommonCrypto/CommonCryptor.h>

#import "NSData+AES256.h"

//密钥key：q6Ur3I*Gk1oEYH%F
//密钥偏移量iv：eJyH@kmlQZjjJM0d

#define kaes_key @"q6Ur3I*Gk1oEYH%F"
#define kaes_iv @"eJyH@kmlQZjjJM0d"

@interface NSString (AES256)

-(NSString *) aes256_encrypt:(NSString *)key;
-(NSString *) aes256_decrypt:(NSString *)key;


-(NSString *) aes256_encrypt_defaultKey;
-(NSString *) aes256_decrypt_defaultKey;

//MD5 加密
- (NSString *)MD5:(NSString *)string;

@end
