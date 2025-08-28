public class ClassroomApp {
	public static void main(String[] args) {
		Classroom room = new Classroom("ExampleRoomName");

		String[] students = {
			"Jeff",
			"Nica",
			"William Marquillius Norbert Smithson Norton",
			"Onin",
		};

		room.add_students(students);
		room.list_students();
	}
}

