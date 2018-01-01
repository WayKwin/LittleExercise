import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;


public class CALENDAR {
public static void main(String[] args) throws ParseException {
	

	String temp="2017-10-12";
	DateFormat d=new SimpleDateFormat("yyyy-MM-dd");
	 Date date=d.parse(temp);
	 Calendar c=new GregorianCalendar();
	 c.setTime(date);
	 c.set(c.DATE, 1);// 把输入的日期设为1号
     System.out.println(c.get(c.DAY_OF_WEEK));//获取当前1号是一周的第几天 sunday是1
    //记住是cc.get(c.DAY_OF_WEEK) 如果直接是c.DAY_OF_WEEK 是Calendar类里默认的常量7
      System.out.println(c.getActualMaximum(c.DATE));//获取本月最大的天数
     int maxDayOfMonth=c.getActualMaximum(c.DATE);
   int DAY_OF_WEEK=c.get(c.DAY_OF_WEEK);
	System.out.println("日\t一\t二\t三\t四\t五\t六");
	//循环    减掉了留白5天 就是开始的6天减去一天
	for (int i = 1; i <= c.getActualMaximum(c.DATE)+DAY_OF_WEEK-1; i++) {
		if(i<DAY_OF_WEEK)//把1号之前的星期变成空白
			System.out.print("\t");
		
		else {
			System.out.print(i-DAY_OF_WEEK+1+"\t"); //从第5天开始是1号  如果不加1是0;
		if(i%7==0)
			System.out.println();
		}
	}


}
}
