import java.util.*;
public class ItermAttri {
	public float item_id;//商品编号
	public String item_geohash;//商品所属位置
	public HashMap<Integer,Integer> item_behavior;//商品购买行为的统计量
	public float item_category;//商品所属类别
	public int time;//商品购买时间
	public boolean isclicked;//最近三天是否被点击
	public boolean iscollected;//最近三天是否被收藏
	public boolean isadded;//最近三天是否加购物车
}
