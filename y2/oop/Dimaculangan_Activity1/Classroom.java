import java.util.ArrayList; // better name for "vector" tbh
import java.util.Collections;

class Classroom {
	private String class_name;
	private int population;
	private ArrayList<String> students;

	Classroom(String name) {
		this.students = new ArrayList<String>();
		this.class_name = name;
		this.population = 0;
	}

	public void add_students(String[] new_students) {
		for (String name : new_students) {
			this.students.add(name);
		}
		show_population(true);
	}

	public void add_student(String new_student) {
		this.students.add(new_student);
		show_population(true);
	}

	public void list_students() {
		System.out.println("The students in class " + class_name + " are:");
		for (String name : students) {
			System.out.println("- " + name);
		}
	}

	public int show_population(boolean log_to_stdout) {
		this.students.sort(null);
		this.population = students.size();

		if (log_to_stdout) {
			System.out.println("There are now " + population + " students in class " + class_name + '.');
		}
		
		return population;
	}
}

