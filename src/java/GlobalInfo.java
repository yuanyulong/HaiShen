
public class GlobalInfo {
   /*
	public static String host="192.168.133.141";//����ip��ַ
	public static String port="3306";//�˿ں�
	public static String dbname="AlibabaTC";//���ݿ�����
	public static String username="root";//�û���
	public static String password="root123";//����
    */

	public static String host="192.168.133.141";//����ip��ַ
	public static String port="3306";//�˿ں�
	public static String dbname="AlibabaTC";//���ݿ�����
	public static String username="root";//�û���
	public static String password="root123";//�����Լ���
	public static GlobalInfo gi = null;
	//Ĭ�Ϲ��캯��
	private GlobalInfo()
	{

	}


    public void setHost(String hostStr) {
        host = hostStr;
    }


    public void setPort(String portStr) {
        port = portStr;
    }

    public void setUsername(String usernameStr) {
        username = usernameStr;
    }


    public void setPassword(String passwordStr) {
        password = passwordStr;
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
