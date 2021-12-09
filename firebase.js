var config = {
	apiKey: "mZl2OtTvUh4VQ7y2Tt1Jt1JkfGDyoXEeJdtK27oP",
	authDomain: "iot2021-d27af-default-rtdb.firebaseio.com",
	databaseURL: "https://iot2021-d27af-default-rtdb.firebaseio.com",
	projectId: "iot2021-d27af",
	storageBucket: "iot2021-d27af.appspot.com",
	messagingSenderId : "520556676422"
};

firebase.initializeApp(config);

var var_lista = document.getElementById("div_lista");
var dados = ""

var dbSensorThiago = firebaseRef = firebase.database().ref().child("Thiago");
var dbSensorVinicius = firebaseRef = firebase.database().ref().child("Vinicius");

dbSensorThiago.on('child_added',function(snapshot){
	var sensorThiago = snapshot.val();

	dbSensorVinicius.on('child_added',function(snapshot){

		var sensorVinicius = snapshot.val();
		dados = "<table class = 'table table-bordered'>"+
					"<thead>"+
						"<tr>"+
							"<th scope='col'>Thiago</th>"+
							"<th scope='col'>Vinícius</th>"+
						"</tr>"+
					"</thead>"+
					"<tbody>"+
						"<tr>"+
							"<td>"+sensorThiago+"</td>"+
							"<td>"+sensorVinicius+"</td>"+
						"</tr>"+
					"</tbody>"+
				"</table>" + dados;

		var_lista.innerHTML = dados;
	})
})

// dbSensorVinicius.on('child_added',function(snapshot){
// 	var sensorVinicius = snapshot.val();

	
// })