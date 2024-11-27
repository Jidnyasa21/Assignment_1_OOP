import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Calculator extends JFrame implements ActionListener {
    JTextField display;
    JButton[] buttons;
    String operator;
    double num1, num2, result;

    public Calculator() {
        display = new JTextField();
        add(display, BorderLayout.NORTH);

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(4, 4));
        add(panel);

        String[] labels = {"7", "8", "9", "/", "4", "5", "6", "*", "1", "2", "3", "-", "C", "0", "=", "+"};
        buttons = new JButton[16];

        for (int i = 0; i < labels.length; i++) {
            buttons[i] = new JButton(labels[i]);
            buttons[i].addActionListener(this);
            panel.add(buttons[i]);
        }

        setTitle("Calculator");
        setSize(300, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();
        if ("0123456789".contains(command)) {
            display.setText(display.getText() + command);
        } else if ("/*-+".contains(command)) {
            operator = command;
            num1 = Double.parseDouble(display.getText());
            display.setText("");
        } else if (command.equals("=")) {
            num2 = Double.parseDouble(display.getText());
            switch (operator) {
                case "+" -> result = num1 + num2;
                case "-" -> result = num1 - num2;
                case "*" -> result = num1 * num2;
                case "/" -> result = num1 / num2;
            }
            display.setText(String.valueOf(result));
        } else if (command.equals("C")) {
            display.setText("");
        }
    }

    public static void main(String[] args) {
        new Calculator();
    }
}
