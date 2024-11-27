import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class TextEditor extends JFrame implements ActionListener {
    JTextArea textArea;
    JLabel statusBar;
    JFileChooser fileChooser;

    public TextEditor() {
        setTitle("Text Editor");
        setSize(500, 500);

        textArea = new JTextArea();
        add(new JScrollPane(textArea), BorderLayout.CENTER);

        JMenuBar menuBar = new JMenuBar();
        JMenu fileMenu = new JMenu("File");
        JMenuItem open = new JMenuItem("Open");
        JMenuItem save = new JMenuItem("Save");
        JMenuItem clear = new JMenuItem("Clear");
        JMenuItem exit = new JMenuItem("Exit");

        fileMenu.add(open);
        fileMenu.add(save);
        fileMenu.add(clear);
        fileMenu.add(exit);
        menuBar.add(fileMenu);
        setJMenuBar(menuBar);

        statusBar = new JLabel(" Characters: 0");
        add(statusBar, BorderLayout.SOUTH);

        open.addActionListener(this);
        save.addActionListener(this);
        clear.addActionListener(this);
        exit.addActionListener(this);
        textArea.addKeyListener(new KeyAdapter() {
            public void keyReleased(KeyEvent e) {
                statusBar.setText(" Characters: " + textArea.getText().length());
            }
        });

        fileChooser = new JFileChooser();

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();
        if (command.equals("Open")) {
            if (fileChooser.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) {
                try (BufferedReader br = new BufferedReader(new FileReader(fileChooser.getSelectedFile()))) {
                    textArea.read(br, null);
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
        } else if (command.equals("Save")) {
            if (fileChooser.showSaveDialog(this) == JFileChooser.APPROVE_OPTION) {
                try (BufferedWriter bw = new BufferedWriter(new FileWriter(fileChooser.getSelectedFile()))) {
                    textArea.write(bw);
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
        } else if (command.equals("Clear")) {
            textArea.setText("");
        } else if (command.equals("Exit")) {
            System.exit(0);
        }
    }

    public static void main(String[] args) {
        new TextEditor();
    }
}
