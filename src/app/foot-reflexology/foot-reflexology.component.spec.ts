import { ComponentFixture, TestBed } from '@angular/core/testing';

import { FootReflexologyComponent } from './foot-reflexology.component';

describe('FootReflexologyComponent', () => {
  let component: FootReflexologyComponent;
  let fixture: ComponentFixture<FootReflexologyComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ FootReflexologyComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(FootReflexologyComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
