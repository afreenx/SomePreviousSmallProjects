package application;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;

//import javafx.scene.Scene;
//import javafx.scene.control.ScrollPane;
import java.io.File;
import java.net.URL;
//import java.util.ArrayList;
import java.util.ResourceBundle;
import java.util.Scanner;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.*;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

//import javafx.stage.Stage;
//import javafx.stage.Stage;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;

public class MController implements Initializable{
	@FXML
	private Label myLabel;
	@FXML
	private TextField Nnumber;
	@FXML
	private Button myButton;
	@FXML
	private Button onlyFile;
	@FXML
	//private TextArea myTextArea;
	//@FXML
	private Button myReset;
	@FXML
	private ListView<String> myListView;
	
	//ArrayList<String> arr1 = new ArrayList<String>();
	ObservableList<String> arr1 = FXCollections.observableArrayList();
	
	
	public int N_file;
	

	
	
	
	// Event Listener on Button[#myButton].onAction
	@FXML
	public void enterClick(ActionEvent event) {
		//Stage mainWindow (Stage) Nnumber.getScene().getWindow();
		try {
		N_file = Integer.parseInt(Nnumber.getText());
		}catch(Exception e) {
			System.out.println("Error");
		}
		FileIO obj = new FileIO();
		//obj.setMainVar(N_file);
		obj.produceOutput(N_file);
		
		//TextArea outputtxt = new TextArea();
		//Stage mainWindow = (Stage) myTextArea.getScene().getWindow();
		//myTextArea.appendText("The Hexagonal Cross Primes are generated below:" +"\n");
		File file = new File("results.txt");
		try (Scanner input = new Scanner(file)) {
		    while (input.hasNextLine()) {
		        //myTextArea.appendText(input.nextLine() + " \n");
		    	arr1.add(input.nextLine());
		        
		    }
		    myListView.getItems().addAll(arr1);
		} catch (Exception ex) {
		    ex.printStackTrace();
		}
		//myTextArea.appendText("\n" + "Click Reset Button if you want to try another N value");
		
		//ScrollPane scrollPane = new ScrollPane();
        //scrollPane.setContent(myTextArea);
		
		//String displayV = "Hello";
		//myTextArea.setText(displayV);
		    
		}
	
	public int getN() {
		return N_file;
	}
	
	@FXML
	public void resetClick(ActionEvent event) {
		//myTextArea.clear();
		arr1.clear();
		myListView.getItems().clear();
		
	}

	@Override
	public void initialize(URL arg0, ResourceBundle arg1) {
		// TODO Auto-generated method stub
		
	}
	}
	   
	

