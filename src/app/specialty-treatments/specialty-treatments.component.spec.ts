import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SpecialtyTreatmentsComponent } from './specialty-treatments.component';

describe('SpecialtyTreatmentsComponent', () => {
  let component: SpecialtyTreatmentsComponent;
  let fixture: ComponentFixture<SpecialtyTreatmentsComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SpecialtyTreatmentsComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SpecialtyTreatmentsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
