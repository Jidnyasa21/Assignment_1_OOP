import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class StudentManagement extends JFrame implements ActionListener {
    JTextField idField, nameField, ageField, genderField, deptField;
    JButton addButton, updateButton, deleteButton, viewButton;
    JTable table;
    DefaultTableModel model;
    Connection conn;

    public StudentManagement() {
        // Database Connection
        try {
            conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/student_db", "root", "password");
        } catch (Exception e) {
            e.printStackTrace();
        }

        // UI Setup
        setTitle("Student Management System");
        setLayout(new BorderLayout());

        JPanel inputPanel = new JPanel(new GridLayout(6, 2));
        inputPanel.add(new JLabel("Student ID:"));
        idField = new JTextField();
        inputPanel.add(idField);

        inputPanel.add(new JLabel("Name:"));
        nameField = new JTextField();
        inputPanel.add(nameField);

        inputPanel.add(new JLabel("Age:"));
        ageField = new JTextField();
        inputPanel.add(ageField);

        inputPanel.add(new JLabel("Gender:"));
        genderField = new JTextField();
        inputPanel.add(genderField);

        inputPanel.add(new JLabel("Department:"));
        deptField = new JTextField();
        inputPanel.add(deptField);

        addButton = new JButton("Add");
        addButton.addActionListener(this);
        inputPanel.add(addButton);

        updateButton = new JButton("Update");
        updateButton.addActionListener(this);
        inputPanel.add(updateButton);

        deleteButton = new JButton("Delete");
        deleteButton.addActionListener(this);
        inputPanel.add(deleteButton);

        viewButton = new JButton("View");
        viewButton.addActionListener(this);
        inputPanel.add(viewButton);

        add(inputPanel, BorderLayout.NORTH);

        model = new DefaultTableModel(new String[]{"ID", "Name", "Age", "Gender", "Department"}, 0);
        table = new JTable(model);
        add(new JScrollPane(table), BorderLayout.CENTER);

        setSize(600, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        try {
            if (e.getSource() == addButton) {
                PreparedStatement stmt = conn.prepareStatement("INSERT INTO students VALUES (?, ?, ?, ?, ?)");
                stmt.setInt(1, Integer.parseInt(idField.getText()));
                stmt.setString(2, nameField.getText());
                stmt.setInt(3, Integer.parseInt(ageField.getText()));
                stmt.setString(4, genderField.getText());
                stmt.setString(5, deptField.getText());
                stmt.executeUpdate();
                JOptionPane.showMessageDialog(this, "Record Added");
            } else if (e.getSource() == updateButton) {
                PreparedStatement stmt = conn.prepareStatement("UPDATE students SET name=?, age=?, gender=?, department=? WHERE id=?");
                stmt.setString(1, nameField.getText());
                stmt.setInt(2, Integer.parseInt(ageField.getText()));
                stmt.setString(3, genderField.getText());
                stmt.setString(4, deptField.getText());
                stmt.setInt(5, Integer.parseInt(idField.getText()));
                stmt.executeUpdate();
                JOptionPane.showMessageDialog(this, "Record Updated");
            } else if (e.getSource() == deleteButton) {
                PreparedStatement stmt = conn.prepareStatement("DELETE FROM students WHERE id=?");
                stmt.setInt(1, Integer.parseInt(idField.getText()));
                stmt.executeUpdate();
                JOptionPane.showMessageDialog(this, "Record Deleted");
            } else if (e.getSource() == viewButton) {
                PreparedStatement stmt = conn.prepareStatement("SELECT * FROM students");
                ResultSet rs = stmt.executeQuery();
                model.setRowCount(0);
                while (rs.next()) {
                    model.addRow(new Object[]{rs.getInt("id"), rs.getString("name"), rs.getInt("age"), rs.getString("gender"), rs.getString("department")});
                }
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new StudentManagement();
    }
}
