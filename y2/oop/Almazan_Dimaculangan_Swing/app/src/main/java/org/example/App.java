package org.example;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List; 

public class App {
    public static void main(String[] args) {
		JFrame window = new JFrame("Test Window");

		Student s = new Student("Test", 18, "SKB");

		System.out.println(s.toString());
    }
}
