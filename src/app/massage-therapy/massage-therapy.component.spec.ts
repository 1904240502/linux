import { ComponentFixture, TestBed } from '@angular/core/testing';

import { MassageTherapyComponent } from './massage-therapy.component';

describe('MassageTherapyComponent', () => {
  let component: MassageTherapyComponent;
  let fixture: ComponentFixture<MassageTherapyComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ MassageTherapyComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(MassageTherapyComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
