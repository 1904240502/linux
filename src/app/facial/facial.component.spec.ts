import { ComponentFixture, TestBed } from '@angular/core/testing';

import { FacialComponent } from './facial.component';

describe('FacialComponent', () => {
  let component: FacialComponent;
  let fixture: ComponentFixture<FacialComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ FacialComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(FacialComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
