package treefile;

import java.io.File;

public class FileTreee {
	public static void main(String[] args) {
		File f=new File("d:/Java文件类/");//当前目录为根节点 
		//File f2=new File("d:/娃娃啊");//如果不存在目录就没有子节点
		printFile(f,0);
	   System.out.println(f.isDirectory());
	}
	static void printFile(File file,int level){
		for(int i=0;i<level;i++){
			System.out.print("-");
		}
		System.out.println(file.getName());
		//通过结果可以发现,检测到1是文件夹,调用递归把1遍历完;然后回到JAVA文件类,
		//检测到2也是文件夹,调用递归遍历a完,
		if(file.isDirectory()){
			File[] files=file.listFiles();//就是普通的保存当前目录下的文件(目录),层层遍历树状是递归实现的i3
			for( int i=0;i<files.length;i++){
				printFile(files[i],level+1);
			}
		}
	}
}
