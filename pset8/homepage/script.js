let str = "This is your new pet"
let dogs = ["images/dogs/dog1.jpg", "images/dogs/dog2.jpg", "images/dogs/dog3.jpg", "images/dogs/dog4.jpg", "images/dogs/dog5.jpg", "images/dogs/dog6.jpg"];
let cats = ["images/cats/cat1.jpg","images/cats/cat2.jpg", "images/cats/cat3.jpg", "images/cats/cat4.jpg", "images/cats/cat5.jpg", "images/dogs/dog6.jpg" ];
let birds = ["images/birds/bird1.jpg","images/birds/bird2.jpg","images/birds/bird3.jpg","images/birds/bird4.jpg","images/birds/bird5.jpg","images/birds/bird6.jpg"];
let hamsters = ["images/hamsters/hamster1.jpg", "images/hamsters/hamster1.jpg", "images/hamsters/hamster2.jpg", "images/hamsters/hamster3.jpg", "images/hamsters/hamster4.jpg","images/hamsters/hamster5.jpg","images/hamsters/hamster6.jpg"];
let pets = [dogs, cats, birds, hamsters];
function randomInt(max){
    return Math.floor(Math.random() * max);
}
function changepic(){
    //document.querySelector('#picture').src=dogs[randomInt(dogs.length)];
    document.querySelector('#picture').src=pets[randomInt(pets.length)][randomInt(dogs.length)];
    document.querySelector('#pet_txt').innerHTML = str + "!";
}


document.addEventListener('DOMContentLoaded', function(){
    document.querySelector('.btn').addEventListener('click',function(){
        changepic();
    });
});

