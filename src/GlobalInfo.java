
public class GlobalInfo {
	public static String host="192.168.133.141";//����ip��ַ
	public static String port="3306";//�˿ں�
	public static String dbname="AlibabaTC";//���ݿ�����
	public static String username="root";//�û���
	public static String password="root123";//����
	public static GlobalInfo gi = null;
	//Ĭ�Ϲ��캯��
	private GlobalInfo()
	{
		
	}
	//��̬��������
	public static GlobalInfo getInstance()
	{
		if(gi == null)
		{
			gi = new GlobalInfo();
		}
		return gi;
	}
}
