import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-massage-therapy',
  templateUrl: './massage-therapy.component.html',
  styleUrls: ['./massage-therapy.component.css']
})
export class MassageTherapyComponent implements OnInit {
 
  public priceone : number;
  constructor() { 
    this.priceone = 60;
  }

  ngOnInit(): void {
  }

}
