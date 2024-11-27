import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class QuizApp extends JFrame implements ActionListener {
    JLabel questionLabel;
    JRadioButton[] options;
    JButton nextButton;
    ButtonGroup bg;
    int current = 0, score = 0;

    String[][] questions = {
        {"What is the capital of France?", "Paris", "London", "Berlin", "Madrid", "Paris"},
        {"Which is the largest planet?", "Mars", "Earth", "Jupiter", "Saturn", "Jupiter"},
        {"What is 2 + 2?", "3", "4", "5", "6", "4"}
    };

    public QuizApp() {
        setTitle("Quiz Application");
        setLayout(new GridLayout(6, 1));

        questionLabel = new JLabel("");
        add(questionLabel);

        options = new JRadioButton[4];
        bg = new ButtonGroup();

        for (int i = 0; i < 4; i++) {
            options[i] = new JRadioButton();
            bg.add(options[i]);
            add(options[i]);
        }

        nextButton = new JButton("Next");
        nextButton.addActionListener(this);
        add(nextButton);

        displayQuestion();

        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void displayQuestion() {
        questionLabel.setText(questions[current][0]);
        for (int i = 0; i < 4; i++) {
            options[i].setText(questions[current][i + 1]);
        }
    }

    public void actionPerformed(ActionEvent e) {
        for (int i = 0; i < 4; i++) {
            if (options[i].isSelected() && options[i].getText().equals(questions[current][5])) {
                score++;
            }
        }

        current++;
        if (current < questions.length) {
            displayQuestion();
            bg.clearSelection();
        } else {
            JOptionPane.showMessageDialog(this, "Quiz Over! Your Score: " + score);
            System.exit(0);
        }
    }

    public static void main(String[] args) {
        new QuizApp();
    }
}
