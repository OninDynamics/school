package org.example;

class Student {
	private String name;
	private int age;
	private String course;

	public Student(String name, int age, String course) {
		this.name = name;
		this.age = age;
		this.course = course;
	}

	public String getName() {
		return name;
	}

	public int getAge() {
		return age;
	}

	public String getCourse() {
		return course;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public void setCourse(String course) {
		this.course = course;
	}

	@Override
	public String toString() {
		return "Name: " + name + ", Age: " + age + ", Course: " + course;
	}
}
