import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SpecialsGiftcardsComponent } from './specials-giftcards.component';

describe('SpecialsGiftcardsComponent', () => {
  let component: SpecialsGiftcardsComponent;
  let fixture: ComponentFixture<SpecialsGiftcardsComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SpecialsGiftcardsComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SpecialsGiftcardsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
