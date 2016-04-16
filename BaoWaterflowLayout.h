//
//  BaoWaterflowLayout.h
//  01-瀑布流


#import <UIKit/UIKit.h>

@class BaoWaterflowLayout;

@protocol BaoWaterflowLayoutDelegate <NSObject>
@required
// 成为代理设置瀑布流的宽度
- (CGFloat)waterflowLayout:(BaoWaterflowLayout *)waterflowLayout heightForItemAtIndex:(NSUInteger)index itemWidth:(CGFloat)itemWidth;

@optional
// 代理方法中设置瀑布流 列的个数
- (NSInteger)columnCountInWaterflowLayout:(BaoWaterflowLayout *)waterflowLayout;
// 代理方法设置瀑布流 列间距
- (CGFloat)columnMarginInWaterflowLayout:(BaoWaterflowLayout *)waterflowLayout;
// 代理方法设置瀑布流 行间距
- (CGFloat)rowMarginInWaterflowLayout:(BaoWaterflowLayout *)waterflowLayout;
// 代理方法设置瀑布流 内边距(在父控件中上,左,下,右间距)
- (UIEdgeInsets)edgeInsetsInWaterflowLayout:(BaoWaterflowLayout *)waterflowLayout;
@end

@interface BaoWaterflowLayout : UICollectionViewLayout
/** 代理 */
@property (nonatomic, weak) id<BaoWaterflowLayoutDelegate> delegate;
@end
