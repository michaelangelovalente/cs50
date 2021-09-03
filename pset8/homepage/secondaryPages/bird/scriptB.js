let str = "This is your new pet bird!"

let birds = ["../../images/birds/bird1.jpg","../../images/birds/bird2.jpg", "../../images/birds/bird3.jpg", "../../images/birds/bird4.jpg", "../../images/birds/bird5.jpg", "../../images/birds/bird6.jpg" ];

function randomInt(max){
    return Math.floor(Math.random() * max);
}
function changepic(){
    //document.querySelector('#picture').src=dogs[randomInt(dogs.length)];
    document.querySelector('#picture').src= birds[randomInt(birds.length)];
    document.querySelector('#pet_txt').innerHTML = str;
}


document.addEventListener('DOMContentLoaded', function(){
    document.querySelector('.btn').addEventListener('click',function(){
        changepic();
    });
});

