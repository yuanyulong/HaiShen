import java.util.*;
public class UserAttri {
	public class ItemBehavior {
		public int item_id;
		public int count;
	}
	public float user_id;//�û��ı��
//�û��Ĺ�������
	//ǰ������Խ��˵�����û�Խϲ��o2o�Ĺ�����ʽ
	public int usercount;//�û�Ƶ��	
	public HashMap<Float,Integer> categorycount;//�û�������Ʒ���������	
	public HashMap<String,Integer> itemcount;//�û�������Ʒ������
	
	public HashMap<Integer,Integer> behaviorcount;//ÿ���û��������͵�ͳ��
	public HashMap<Integer,Integer> behaviorbuycount;//ÿ���û���������ת��Ϊ�����ͳ��
//ƥ����
	public HashMap<String,HashMap<Integer,Integer>> geobehaviorcount;//��ͬ����λ�õ���Ϊͳ����
	public Vector <String> itemcategory;//ÿ���û�������Ʒ������
	public HashMap<Integer,Time> behaviortime;//��ͬ������������Ӧ��ʱ��
	public ItemBehavior[] clicked_nobuy;//�������������δ�������Ʒ
	public ItemBehavior[] collected_nobuy;//��������ղص�δ�������Ʒ
	public ItemBehavior[] shopingcart_nobuy;//���������빺�ﳵ��δ�������Ʒ
}
