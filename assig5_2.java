// Note: Configure MySQL connection and database schema beforehand.
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class LoginForm extends JFrame implements ActionListener {
    JTextField usernameField, emailField;
    JPasswordField passwordField;
    JButton registerButton, loginButton;
    Connection conn;

    public LoginForm() {
        // Initialize database connection
        try {
            conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb", "root", "password");
        } catch (Exception e) {
            e.printStackTrace();
        }

        // Create UI
        setTitle("Login and Registration");
        setSize(300, 300);
        setLayout(new GridLayout(4, 2));
        
        add(new JLabel("Username:"));
        usernameField = new JTextField();
        add(usernameField);
        
        add(new JLabel("Password:"));
        passwordField = new JPasswordField();
        add(passwordField);
        
        add(new JLabel("Email (For Registration):"));
        emailField = new JTextField();
        add(emailField);

        loginButton = new JButton("Login");
        loginButton.addActionListener(this);
        add(loginButton);
        
        registerButton = new JButton("Register");
        registerButton.addActionListener(this);
        add(registerButton);

        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e) {
        String username = usernameField.getText();
        String password = new String(passwordField.getPassword());
        String email = emailField.getText();

        try {
            if (e.getSource() == registerButton) {
                PreparedStatement stmt = conn.prepareStatement("INSERT INTO users(username, password, email) VALUES (?, ?, ?)");
                stmt.setString(1, username);
                stmt.setString(2, password);
                stmt.setString(3, email);
                stmt.executeUpdate();
                JOptionPane.showMessageDialog(this, "Registration Successful");
            } else if (e.getSource() == loginButton) {
                PreparedStatement stmt = conn.prepareStatement("SELECT * FROM users WHERE username = ? AND password = ?");
                stmt.setString(1, username);
                stmt.setString(2, password);
                ResultSet rs = stmt.executeQuery();
                if (rs.next()) {
                    JOptionPane.showMessageDialog(this, "Login Successful");
                } else {
                    JOptionPane.showMessageDialog(this, "Invalid Credentials");
                }
            }
        } catch (SQLException ex) {
            ex.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new LoginForm();
    }
}
