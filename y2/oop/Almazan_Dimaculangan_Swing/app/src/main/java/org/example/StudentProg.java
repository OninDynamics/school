package org.example;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List; 


public class StudentProg extends JFrame {
  private JTextField nameField, ageField, courseField;
  private JTextArea displayArea; 
  private JButton addButton; 
  
  private List<Student> students = new ArrayList<>();

  public StudentProg() { 
    setTitle("StudentProg1");
    setSize(500,500);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    JPanel inputPanel = new JPanel(); 
    inputPanel.setLayout(new GridLayout(4, 2, 5, 5));
    inputPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

    inputPanel.add(new JLabel("Name: "));
    nameField = new JTextField();
    inputPanel.add(nameField);

    inputPanel.add(new JLabel("Age: "));
    ageField = new JTextField();
    inputPanel.add(ageField);

    inputPanel.add(new JLabel("Course: "));
    courseField = new JTextField();
    inputPanel.add(courseField);

    addButton = new JButton("Add Student");
    inputPanel.add(new JLabel(""));
    inputPanel.add(addButton);

    displayArea = new JTextArea();
    displayArea.setEditable(false);
    JScrollPane scrollPane = new JScrollPane(displayArea);

    add(inputPanel, BorderLayout.NORTH);
    add(scrollPane, BorderLayout.CENTER);
 
    addButton.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) { 
        addStudent();
      }
    });
  }

  private void addStudent() {   
    try { 
      String name = nameField.getText();
      int age = Integer.parseInt(ageField.getText()); 
      String course = courseField.getText();
      
      Student newStudent = new Student(name, age, course);
    
      students.add(newStudent);
      
      displayArea.setText("");
      for (Student s : students) {
        displayArea.append(s.toString() + "\n");
      } 
  
      nameField.setText("");
      ageField.setText(""); 
      courseField.setText("");

      } catch (NumberFormatException ex) { 
          JOptionPane.show().MessageDialog(this, "Please enter a valid age,", "Error", JOptionPane.ERROR_MESSAGE);
     }
}
