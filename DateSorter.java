import java.util.ArrayList;
import java.util.Collections;

public class DateSorter {
	// demo:
	public static void main (String[] args) {
		String[] raw_time = {
			"17-12-14 23:59",
			"17-12-28 23:59",
			"17-12-07 23:59",
			"17-12-21 23:59",
		};
		ArrayList<String> tarr = new ArrayList<String>();
		for (String t : raw_time) {
			tarr.add(new String(t));
		}

		Collections.sort(tarr);

		for (String t : tarr) {
			System.out.println(t);
		}
	}
}
