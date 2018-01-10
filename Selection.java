
public class Selection extends Sort {

	@Override
	/**
	 * 冒泡排序在内层循环交换
	 * 
	 * 选择排序在内部标记最小元素 比较 n*(n-1)/2次
	 * 在外层循环交换 最差情况下要交换N次
	 * 
	 */
	
	public void sort(Comparable[] a) {
		for (int i = 0; i < a.length; i++) {
			int min=i;
			for(int j=i+1;j<a.length;j++){//比较(N-1	)+(N-2).....2+1次  每次交换一次
				if(less(a[j],a[min]))
					min=j;//找出最小的数的下标(比较)
			}
			exch(a,i,min);//和默认最小元素(最左边的)交换元素(交换)
		}	
	}
public static void main(String[] args) {
	Selection s=new Selection();
	Comparable[] a={4,3,2,1};//自动装箱
	s.sort(a);
	show(a);
}
}
