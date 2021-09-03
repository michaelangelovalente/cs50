let str = "This is your new pet dog!"

let dogs = ["../../images/dogs/dog1.jpg","../../images/dogs/dog2.jpg", "../../images/dogs/dog3.jpg", "../../images/dogs/dog4.jpg", "../../images/dogs/dog5.jpg", "../../images/dogs/dog6.jpg" ];

function randomInt(max){
    return Math.floor(Math.random() * max);
}
function changepic(){
    //document.querySelector('#picture').src=dogs[randomInt(dogs.length)];
    document.querySelector('#picture').src= dogs[randomInt(dogs.length)];
    document.querySelector('#pet_txt').innerHTML = str;
}


document.addEventListener('DOMContentLoaded', function(){
    document.querySelector('.btn').addEventListener('click',function(){
        changepic();
    });
});

