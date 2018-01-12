
public class Shell extends Sort{

	@Override
	public void sort(Comparable[] a) {
		int N=a.length;
		int h=1;
		while(h<N/3)
			h=h*3+1; //1,4,13,
		while(h>=1){
			// 每组的组间距为H  每次循环把每组都变得有序
			for(int i=h;i<N;i++){//从h开始左往右处理跨组处理
			    for(int j=i;j>=h&&less(a[j],a[j-h]);j-=h){//h是门槛(控制最后一个循环第二个元素和第一个元素比)
			    	exch(a,j,j-h);     //如果J是H 表明是第一组的a[0]和a[h]比    第二组的H+1就是和a[1]比,当h小于2h的时候只比较一次
			    	                   //=2h会比较两次,  所以一共有h组  每组有nh个元素
			    }
			}
			//把组间距缩小,不断逼近1
			h/=3;
		} 
	
	}
public static void main(String[] args) {
	Shell s=new Shell();
	Comparable[] a={4,3,2,1};//自动装箱
	s.sort(a);
	show(a);
}
}
