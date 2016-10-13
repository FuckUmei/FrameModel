//
//  PickerView.h
//  xingzhengbao
//
//  Created by specter on 16/3/30.
//  Copyright © 2016年 XZB. All rights reserved.
//  日期选择器视图

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PickerViewDelegate

-(void)changePickerViewData:(UIPickerView *)pickerview string:(NSString *)data;

@end

@interface PickerView : UIButton
{
    id<PickerViewDelegate> deleage;
}
@property(assign,nonatomic)id<PickerViewDelegate> delegate;
/** 内部视图 */
@property (nonatomic, strong) UIView *contentView;
/** 日期选择器 */
@property (nonatomic,strong)UIDatePicker *datePicker;
/** 左边的按钮 */
@property (nonatomic, strong)UIButton *buttonLeft;
/** 右边的按钮 */
@property (nonatomic, strong)UIButton *buttonRight;
/** 默认label */
@property (nonatomic, strong)UILabel *defultLabel;
/** 标题label */
@property (nonatomic, strong)UILabel *labelTitle;
/** 字体，default is nil (system font 17 plain) */
@property(null_resettable, nonatomic,strong) UIFont   *font;
/** 字体颜色，default is nil (text draws black) */
@property(null_resettable, nonatomic,strong) UIColor  *titleColor;
/** 按钮边框颜色颜色，default is RGB(205, 205, 205) */
@property(null_resettable, nonatomic,strong) UIColor  *borderButtonColor;
/** 选择器的高度，default is 240 */
@property (nonatomic, assign)CGFloat heightPicker;
/** 选择器的数据*/
@property (nonatomic, strong)NSString *strData;
/** 标题显示模式*/
@property (nonatomic, strong)NSString *titleType;

- (void)show;
- (void)showYYMMdd;

@end

NS_ASSUME_NONNULL_END