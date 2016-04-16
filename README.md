# BaoWaterflowLayout-
一个超好用,超轻量级,代理设计模式(协议编程)实现瀑布流的小框架.

- 相关代理协议:

  ```objc
  @protocol BaoWaterflowLayoutDelegate <NSObject>
  @required
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
  ```

  ​

- 使用方法:

  ```objc
  // 在你需要使用瀑布流的控制器中导入头文件,遵循代理.
  #import "BaoWaterflowLayout.h"

  @interface ViewController () <UICollectionViewDataSource, BaoWaterflowLayoutDelegate>
    
    // 接着....
    - (void)setupLayout
  {
      // 创建布局
      BaoWaterflowLayout *layout = [[BaoWaterflowLayout alloc] init];
      layout.delegate = self;
      
      // 创建CollectionView
      UICollectionView *collectionView = [[UICollectionView alloc] initWithFrame:self.view.bounds collectionViewLayout:layout];
      collectionView.backgroundColor = [UIColor whiteColor];
      collectionView.dataSource = self;
      [self.view addSubview:collectionView];
      
      // 注册
      [collectionView registerNib:[UINib nibWithNibName:NSStringFromClass([XMGShopCell class]) bundle:nil] forCellWithReuseIdentifier:XMGShopId];
      
      self.collectionView = collectionView;
  }

  // and.....
  #pragma mark - <BaoWaterflowLayoutDelegate> 实现代理方法
  - (CGFloat)waterflowLayout:(BaoWaterflowLayout *)waterflowLayout heightForItemAtIndex:(NSUInteger)index itemWidth:(CGFloat)itemWidth
  {
      return 瀑布流中item宽度
  }

  - (CGFloat)rowMarginInWaterflowLayout:(BaoWaterflowLayout *)waterflowLayout
  {
      return 瀑布流中item行间距
  }

  - (NSInteger)columnCountInWaterflowLayout:(BaoWaterflowLayout *)waterflowLayout
  {
      return 瀑布流中item的列数
  }

  - (UIEdgeInsets)edgeInsetsInWaterflowLayout:(BaoWaterflowLayout *)waterflowLayout
  {
      // 返回瀑布流在父控件中的内边距
      return UIEdgeInsetsMake(10, 20, 30, 100);
  }
  ```

  ​