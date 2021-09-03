let str = "This is your new pet Hamster!"

let birds = ["../../images/hamsters/hamster1.jpg","../../images/hamsters/hamster2.jpg", "../../images/hamsters/hamster3.jpg", "../../images/hamsters/hamster4.jpg", "../../images/hamsters/hamster5.jpg", "../../images/hamsters/hamster6.jpg" ];

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

