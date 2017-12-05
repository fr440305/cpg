import java.util.ArrayList;
import java.util.Collections;

public class DateSorter {
	// demo:
	public static void main (String[] args) {
		String[] raw_time = {
			"16-12-21 23:59",
			"14-12-21 23:59",
			"17-12-21 23:59"
		};
		ArrayList<Time> tarr = new ArrayList<Time>();
		for (String t : raw_time) {
			tarr.add(new Time(t));
		}
		Collections.sort(tarr);
		for (Time t : tarr) {
			System.out.println(t);
		}
		// Output:
		// 14-12-21 23:59
		// 16-12-21 23:59
		// 17-12-21 23:59
	}
}

class Time implements Comparable<Time> {
	public Integer YY;
	public Integer MM;
	public Integer DD;
	public Integer HH;
	public Integer mm;

	public Time (String raw) {
		this.Read(raw);
	}

	// fmt: "YY-MM-DD HH:mm"
	// If read fails, then it returns false.
	public boolean Read(String raw) {
		this.YY = new Integer(raw.substring(0, 2));
		this.MM = new Integer(raw.substring(3, 5));
		this.DD = new Integer(raw.substring(6, 8));
		this.HH = new Integer(raw.substring(9, 11));
		this.mm = new Integer(raw.substring(12, 14));
		return true;
	}

	public String toString() {
		return (
			YY.toString() + "-" +
			MM.toString() + "-" +
			DD.toString() + " " +
			HH.toString() + ":" +
			mm.toString()
		);
	}

	public int compareTo (Time ano) {
		if (this.YY > ano.YY) {
			return 1;
		} else if (this.YY < ano.YY) {
			return -1;
		}
		if (this.MM > ano.MM) {
			return 1;
		} else if (this.MM < ano.MM) {
			return -1;
		}
		if (this.DD > ano.DD) {
			return 1;
		} else if (this.DD < ano.DD) {
			return -1;
		}
		// YY, MM, DD are equal:
		if (this.HH > ano.HH) {
			return 1;
		} else if (this.HH < ano.HH) {
			return -1;
		}
		if (this.mm > ano.mm) {
			return 1;
		} else if (this.mm < ano.mm) {
			return -1;
		}
		return 0;
	}
}
