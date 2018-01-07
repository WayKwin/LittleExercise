
public class Insertion  extends Sort{

	@Override
	public void sort(Comparable[] a) {
		for(int i=1;i<a.length;i++){
			for(int j=i;j>=1&&less(a[j],a[j-1]);j--){//门槛是第二个元素和第一个元素比较
				exch(a,j,j-1);//把新元素和前面已经排好序的元素依次比较
			}
		}
	}
	
	public void sort2(Comparable[] a) {
		for(int i=1;i<a.length;i++){
			Comparable temp=a[i];
			int inserpoint=i-1;
		
			while(inserpoint>=0&&less(temp,a[inserpoint]))//左边的比右边的大,6 3
			{
				a[inserpoint+1]=a[inserpoint];//大的元素往右边移动   6->3 变成 6->6
				inserpoint--;// 
			}
			//最后inserpoint指向比temp小的元素,那么temp要赋值给inserpoint右边的元素
			a[inserpoint+1]=temp;
		}
	}
        public static void main(String[] args) {
        	Insertion eg=new Insertion();
        	Comparable[] a={4,3,2,1};//自动装箱
        	eg.sort2(a);
        	show(a);
		} 
}
