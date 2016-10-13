//
//  PickerView.h
//  xingzhengbao
//
//  Created by specter on 16/3/30.
//  Copyright © 2016年 XZB. All rights reserved.
//  日期选择器视图

#import "PickerView.h"
#import "Common.h"
#import "UIView+Ext.h"

@implementation PickerView

#pragma mark - --- init 视图初始化 ---
- (instancetype)init
{
    self = [super init];
    if (self) {
        [self setupDefault];
        [self setupUI];
    }
    return self;
}

- (void)setupDefault
{
    // 1.设置数据的默认值
    _strData            = @"";
    _font               = CHINESE_SYSTEM(17.0f);
    _titleColor         = [UIColor blackColor];
    _borderButtonColor  = RGB(205, 205, 205);
    _heightPicker       = SCALEHEIGHT(216);
    _delegate           = nil;
    _titleType          = @"yyyy年MM月dd日(EEEE)   HH:mm:ss";
    
    // 2.设置自身的属性
    self.bounds = [UIScreen mainScreen].bounds;
    self.backgroundColor = RGBA(0, 0, 0, 102.0/255);
    self.layer.opacity = 0.0;
    [self addTarget:self action:@selector(remove) forControlEvents:UIControlEventTouchUpInside];
    
    // 3.添加子视图
    [self addSubview:self.contentView];
    [self.contentView addSubview:self.buttonLeft];
    [self.contentView addSubview:self.buttonRight];
//    [self.contentView addSubview:self.defultLabel];
    [self.contentView addSubview:self.labelTitle];
}

- (void)setupUI
{
    
    self.datePicker = [[UIDatePicker alloc]initWithFrame:CGRectMake(0, SCALEWIDTH(44), SCREEN_WIDTH, _heightPicker)];
    self.datePicker.backgroundColor = [UIColor groupTableViewBackgroundColor];
    [self.contentView addSubview:self.datePicker];
    
    [self.datePicker addTarget:self action:@selector(dateChanged:) forControlEvents:UIControlEventValueChanged ];//重点：UIControlEventValueChanged
    
    //设置显示格式
    //默认根据手机本地设置显示为中文还是其他语言
    NSLocale *locale = [[NSLocale alloc] initWithLocaleIdentifier:@"zh_CN"];//设置为中文显示
    self.datePicker.locale = locale;
    
    //当前时间创建NSDate
    NSDate *localDate = [NSDate date];
    //在当前时间加上的时间：格里高利历
    NSCalendar *gregorian = [[NSCalendar alloc] initWithCalendarIdentifier:NSGregorianCalendar];
    NSDateComponents *offsetComponents = [[NSDateComponents alloc] init];
    //设置时间
    [offsetComponents setYear:0];
    [offsetComponents setMonth:0];
    [offsetComponents setDay:10];
    [offsetComponents setHour:20];
    [offsetComponents setMinute:0];
    [offsetComponents setSecond:0];
    //设置最大值时间
    NSDate *maxDate = [gregorian dateByAddingComponents:offsetComponents toDate:localDate options:0];
    //设置属性
    self.datePicker.minimumDate = localDate;
    self.datePicker.maximumDate = maxDate;
   
}

#pragma mark - --- 选择器回掉方法 ---
-(void)dateChanged:(id)sender{
    UIDatePicker *control = (UIDatePicker*)sender;
    NSDate* date = control.date;
    //添加你自己响应代码
//    NSLog(@"dateChanged响应事件：%@",date);
    
    //NSDate格式转换为NSString格式
    NSDate *pickerDate = [self.datePicker date];// 获取用户通过UIDatePicker设置的日期和时间
    NSDateFormatter *pickerFormatter = [[NSDateFormatter alloc] init];// 创建一个日期格式器
    [pickerFormatter setDateFormat:_titleType];
    NSString *dateString = [pickerFormatter stringFromDate:pickerDate];
    
    //打印显示日期时间
//    NSLog(@"格式化显示时间：%@",dateString);
    _strData = dateString;
    self.labelTitle.text = dateString;
    
}

#pragma mark - --- 动画 ---
- (void)show
{
    [[UIApplication sharedApplication].keyWindow addSubview:self];
    [self setCenter:[UIApplication sharedApplication].keyWindow.center];
    [[UIApplication sharedApplication].keyWindow bringSubviewToFront:self];
    
   
    CGRect frameContent =  self.contentView.frame;
    frameContent.origin.y -= self.contentView.height;
    [UIView animateWithDuration:0.3 delay:0 options:UIViewAnimationOptionCurveEaseOut animations:^{
        [self.layer setOpacity:1.0];
        self.contentView.frame = frameContent;
    } completion:^(BOOL finished) {
    }];

}
- (void)showYYMMdd
{
    
    //当前时间创建NSDate
    NSDate *localDate = [NSDate date];
    //在当前时间加上的时间：格里高利历
    NSCalendar *gregorian = [[NSCalendar alloc] initWithCalendarIdentifier:NSGregorianCalendar];
    NSDateComponents *offsetComponents = [[NSDateComponents alloc] init];
    //设置时间
    [offsetComponents setYear:-2];
    [offsetComponents setMonth:0];
    [offsetComponents setDay:0];
    //设置最大值时间
    NSDate *minDate = [gregorian dateByAddingComponents:offsetComponents toDate:localDate options:0];
    //设置属性
    self.datePicker.minimumDate = minDate;
    self.datePicker.maximumDate = localDate;
    self.datePicker.datePickerMode = UIDatePickerModeDate;
    [[UIApplication sharedApplication].keyWindow addSubview:self];
    [self setCenter:[UIApplication sharedApplication].keyWindow.center];
    [[UIApplication sharedApplication].keyWindow bringSubviewToFront:self];
    
    
    CGRect frameContent =  self.contentView.frame;
    frameContent.origin.y -= self.contentView.height;
    [UIView animateWithDuration:0.3 delay:0 options:UIViewAnimationOptionCurveEaseOut animations:^{
        [self.layer setOpacity:1.0];
        self.contentView.frame = frameContent;
    } completion:^(BOOL finished) {
    }];
    
}

- (void)remove
{
    if (_delegate)
    {
        [_delegate changePickerViewData:self.datePicker string:self.strData];
    }
    CGRect frameContent =  self.contentView.frame;
    frameContent.origin.y += self.contentView.height;
    [UIView animateWithDuration:0.3 delay:0 options:UIViewAnimationOptionCurveEaseOut animations:^{
        [self.layer setOpacity:0.0];
        self.contentView.frame = frameContent;
    } completion:^(BOOL finished) {
        [self removeFromSuperview];
    }];
    
}

#pragma mark - --- setters 属性 ---
- (void)setFont:(UIFont *)font
{
    _font = font;
    [self.buttonLeft.titleLabel setFont:font];
    [self.buttonRight.titleLabel setFont:font];
    [self.defultLabel setFont:font];
    [self.labelTitle setFont:font];
}

- (void)setTitleColor:(UIColor *)titleColor
{
    _titleColor = titleColor;
    [self.defultLabel setTextColor:titleColor];
    [self.labelTitle setTextColor:titleColor];
    [self.buttonLeft setTitleColor:titleColor forState:UIControlStateNormal];
    [self.buttonRight setTitleColor:titleColor forState:UIControlStateNormal];
}

- (UIButton *)buttonLeft
{
    if (!_buttonLeft)
    {
        _buttonLeft = [[UIButton alloc]initWithFrame:CGRectMake(10, SCREEN_WIDTH-SCALEHEIGHT(55), SCALEWIDTH(60), SCALEHEIGHT(35))];
        [_buttonLeft setTitle:NSLocalizedString(@"Common_btnExit", nil) forState:UIControlStateNormal];
        [_buttonLeft.titleLabel setFont:AdaptedFontSize(16.0)];
        [_buttonLeft.layer setBorderColor:self.borderButtonColor.CGColor];
        [_buttonLeft.layer setBorderWidth:1.0];
        [_buttonLeft.layer setCornerRadius:3];
        [_buttonLeft setTitleColor:self.titleColor forState:UIControlStateNormal];
        [_buttonLeft.titleLabel setFont:self.font];
        [_buttonLeft addTarget:self action:@selector(selectedCancel) forControlEvents:UIControlEventTouchUpInside];
    }
    return _buttonLeft;
}

- (UIButton *)buttonRight
{
    if (!_buttonRight) {
        CGFloat rightW = self.buttonLeft.width;
        CGFloat rightH = self.buttonLeft.height;
        CGFloat rightX = self.contentView.width - rightW - self.buttonLeft.frame.origin.x;
        CGFloat rightY = self.buttonLeft.frame.origin.y;
        _buttonRight = [[UIButton alloc]initWithFrame:CGRectMake(rightX, rightY, rightW, rightH)];
        [_buttonRight setTitle:NSLocalizedString(@"Common_btnSure", nil) forState:UIControlStateNormal];
        [_buttonRight.layer setBorderColor:self.borderButtonColor.CGColor];
        [_buttonRight.layer setBorderWidth:1.0];
        [_buttonRight.layer setCornerRadius:3];
        [_buttonRight setTitleColor:self.titleColor forState:UIControlStateNormal];
        [_buttonRight.titleLabel setFont:self.font];
        [_buttonRight addTarget:self action:@selector(selectedOk) forControlEvents:UIControlEventTouchUpInside];
    }
    return _buttonRight;
    
}

- (UILabel *)defultLabel
{
    if (!_defultLabel)
    {
        _defultLabel = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, SCALEWIDTH(90), SCALEHEIGHT(44))];
        _defultLabel.text = NSLocalizedString(@"Common_setingDate", nil);
        [_defultLabel setTextAlignment:NSTextAlignmentLeft];
        [_defultLabel setTextColor:self.titleColor];
        [_defultLabel setFont:self.font];
        _defultLabel.adjustsFontSizeToFitWidth = YES;
    }
    return _defultLabel;
}

- (UILabel *)labelTitle
{
    if (!_labelTitle)
    {
        _labelTitle = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, SCREEN_WIDTH, SCALEHEIGHT(44))];
        _labelTitle.text = NSLocalizedString(@"Common_setingDate", nil);
        [_labelTitle setTextAlignment:NSTextAlignmentCenter];
        [_labelTitle setTextColor:self.titleColor];
        [_labelTitle setFont:self.font];
        _labelTitle.adjustsFontSizeToFitWidth = YES;
    }
    return _labelTitle;
}
#pragma mark - --- 初始化子view ---
- (UIView *)contentView
{
    if (!_contentView) {
        CGFloat contentX = 0;
        CGFloat contentY = SCREEN_HEIGHT;
        CGFloat contentW = SCREEN_WIDTH;
        CGFloat contentH = self.heightPicker+SCALEHEIGHT(88);
        _contentView = [[UIView alloc]initWithFrame:CGRectMake(contentX, contentY, contentW, contentH)];
        [_contentView setBackgroundColor:[UIColor whiteColor]];
    }
    return _contentView;
}

#pragma mark - --- event response 事件相应 ---

- (void)selectedOk
{
    [self remove];

}

- (void)selectedCancel
{
    CGRect frameContent =  self.contentView.frame;
    frameContent.origin.y += self.contentView.height;
    [UIView animateWithDuration:0.3 delay:0 options:UIViewAnimationOptionCurveEaseOut animations:^{
        [self.layer setOpacity:0.0];
        self.contentView.frame = frameContent;
    } completion:^(BOOL finished) {
        [self removeFromSuperview];
    }];
//    [self remove];
}

@end

