package myCollection;


/*
 *模拟实现JDK中提供的ArrayList类
 * @author WayKwin
 */
public class MyArryList {
	  Object[] value;
	 int size;

	public int size(){
		return size();
	}
	public int length(){
		return value.length;
	}
	public MyArryList() {
		this(16);//构造器的相互调用
	}

	public MyArryList(int size) {
		value = new Object[size];
	}

	public void add(Object obj) {//放东西
		value[size] = obj;
		size++;
		if(size>value.length-1){
			//装不下了，扩容吧；
			int  newCapacity = value.length*2+2;
			Object[] newList=new Object[newCapacity];
			for (int i = 0; i < value.length; i++) {
		         newList[i]=value[i];//把value的值传给newlist;
			}
			value=newList;
		}
	}
	public void rangeCheck(int index){
		if (index < 0 || index > size - 1) {
			try {
				throw new Exception();// 手动跑出一个异常
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
	public Object get(int index) {
		rangeCheck(index);
		return value[index];

	}
	public int indexOF(Object obj){
		if(obj==null)
      return -1;
		else{
			for (int i = 0; i < value.length; i++) {
				if(obj==value[i]){
					return i;
				}
			}
			return -1;
		}
	}
	public int lastIdexOF(Object obj) {
		if(obj==null)
		      return -1;
		else{
			for (int i =value.length-1; i <=0; i--) {
				if(obj==value[i]){
					return i;
				}
			}
			return -1;
		}
	}
	public Object set(int index,Object obj){
    	rangeCheck(index);
    	Object old=value[index];
    	value[index]=obj;
    	return old;
    }
	public Object insert(int index,Object obj){
		rangeCheck(index);
		int  newCapacity = value.length+1;
		Object[] newList= new Object[newCapacity];
		for (int i = 0; i < index; i++) {
			newList[i]=value[i];
			
		}
		for (int i = newCapacity-1; i >index; i--) {// 把index这个位置空下来
			newList[i]=newList[i-1];//最后一步 把 newlis[index+1]=newlist[index] 把index的值给了他右边的那个
			
		}
		newList[index]=obj;
		value=newList;
		return value;
	}
	public Object delete(int index) {
		rangeCheck(index);
	    for (int i = index; i < value.length-1; i++) {
			value[i]=value[i+1];
		}
	   Object[] newList=new Object[value.length-1];
	   for (int i = 0; i < newList.length; i++) {
			 newList[i]= value[i];
	 		}
	   value=newList;
		return value;
	}
	public static void main(String[] args) {
		MyArryList list = new MyArryList(2);
		list.add("aaa");
		list.add(new Huam("魏长锟"));
		list.add("bbbbb");
        for (int i = 0; i < list.length(); i++) {
        System.out.println(list.value[i]);
		}
	}

}
